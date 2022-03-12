/*===========================================================================
 * cal.c - print calendar for one month or one year
 *
 * compatible with standard unix cal command and inspired by an Amiga port
 * of cal by Gary L. Brant.
 * version 4.0
 *
 * cal [options] [[month] year]    (numerical month argument)
 * or
 * cal [options] [month] [year]    (verbal month argument)
 *
 * (C) 1992-2002 by Unicorn Research Corporation, http://www.unicorn.us.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * - Neither name of Unicorn Research nor the names of its contributors may be
 * used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS `AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *===========================================================================
 */

/*
BASIC DATA STRUCTURE:                                          specialdays()
                                                               pointers:
 char *buf ==>  line[0] -> [......LineWid (default 80).......] lln[0]
                line[1] -> [.................................] lln[1]
                line[2] -> [.................................] lln[2]
                      ...  [.................................] ...
       line[maxappts-1] -> [.................................] lln[maxappts-1]

           line_attr[0] -> [........LineWid (80).............]
           line_attr[1] -> [.................................] allocated
           line_attr[2] -> [.................................] only if
                      ...  [.................................] colors
  line_attr[maxappts-1] -> [.................................] are used
               mon_attr -> [......YEARWID (72)...........]
                wk_attr -> [......YEARWID (72)...........]
               day_attr -> [......YEARWID (72)...........]
           spclday_attr -> [....DAY_DESC (56).....]
*/

/* --- User Configuration ---------------------------------------------------*/

/* When compiling under DOS, define MSDOS.  When compiling under OS/2
 * define OS2.  This allows certain DOS/OS/2'isms to be accessable.
 */
/* #define MSDOS */
/* #define OS2 */

/* To display the calendar in color, define USE_COLOR.  Under MSDOS or
 * OS2, this will cause cal to access the video memory directly to
 * manipulate colors.  Under unix, it will cause cal to use inline ANSI
 * escape codes for colors. */

#define USE_COLOR

/* Most platforms have support for terminal drivers that understand
 * ANSI escape sequences to display colors.  This includes most unix
 * terminals and DOS or OS/2 with the ANSI.SYS driver loaded.
 * Define USE_ANSI when ANSI color support is wanted under those platforms.
 * If left undefined here, it will be defined under unix if USE_COLOR
 * is defined above, and it will be undefined under OS2 and MSDOS.
 * By default OS2 and MSDOS will use video memory (USE_VIDEORAM) if
 * USE_COLOR is defined, unless USE_ANSI is defined here.
 */
/* #define USE_ANSI */

/* Some platforms do not have strncasecmp.  For those, you can define
 * NEEDS_STRNCASECMP and use an internal version.
 */
/* #define NEEDS_STRNCASECMP */

/* --- End User Configuration -----------------------------------------------*/


/* Simply auto detect if we are in a unix style compile enviornment */

#if (defined(__unix__) || defined(UNIX)) && !defined(__DJGPP__)
 #undef MSDOS
 #undef OS2
 #ifndef UNIX
  #define UNIX
 #endif
#endif /* __unix__ */

#ifdef OS2
 #undef MSDOS
 #undef UNIX
#endif /* OS2 */

#ifdef MSDOS
 #undef OS/2
 #undef UNIX
#endif /* MSDOS */

#ifdef __DJGPP__
 #ifndef MSDOS
  #define MSDOS
 #endif
 #undef UNIX
 #undef OS2
 #define far
#endif /* __DJGPP__ */

/* now that we know the operating system, set the color definitions */

#ifdef USE_COLOR
 #ifdef UNIX
  #undef USE_VIDEORAM
  #define USE_ANSI
 #endif
 #if defined(MSDOS) || defined(OS2)
  #ifdef USE_ANSI
   #undef USE_VIDEORAM
  #else
   #undef USE_ANSI
   #define USE_VIDEORAM
  #endif
 #endif
#else
 #undef USE_ANSI
 #undef USE_VIDEORAM
#endif /* USE_COLOR */


#define MAXFILES 8   /* maximum number of data file paths */
#define MAXAPPTS 50  /* maximum number of appointment description lines */
#define CAL_MAXPATH 1024 /* maximum size of path and filename strings */
#define MAXLINE 256  /* maximum length of lines in config files. */

/* Include files for accessing video memory */
#ifdef USE_VIDEORAM
 #ifdef OS2
  #define INCL_SUB
  #include <os2.h>
 #else
  #include <dos.h> /* for int86() */
 #endif /* OS2 */
#endif /* USE_VIDEORAM */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#ifndef UNIX
 #include <io.h>  /* for isatty() */
#endif
#if defined(UNIX) || defined(DJGPP)
 #include <unistd.h>
#endif
#ifdef HAVE_LOCALE_H
 #include <locale.h>
 #ifdef HAVE_LANGINFO_H
  #include <langinfo.h>
 #else
  #include <localeinfo.h> /* libc4 only */
 #endif
#endif /* HAVE_LOCALE_H */

#ifndef max
 #define max(a,b) (((a)>(b))?(a):(b))
#endif /* max */

#ifdef USE_VIDEORAM
 #ifdef MSDOS
  #ifdef __DJGPP__
   #include <sys/farptr.h>  /* for _farpokeb() */
   #include <go32.h>        /* for _dos_ds     */
   #define MK_FP(seg,off) ((unsigned long)(seg)*16L+(off))
   unsigned long video, tmpvideo;
  #else
   #ifndef MK_FP
    #define MK_FP(seg,off) (void far *)(((unsigned long)(seg)<<16)|(unsigned)(off))
   #endif /* !MK_FP */
   char far *video, far *tmpvideo;
  #endif /* __DJGPP__ */
  union REGS reg;
 #endif /* MSDOS */
#endif /* USE_VIDEORAM */


#define THURSDAY        4        /* Used during reformation calculations   */
#define SATURDAY        6        /* 1 Jan 1 was a Saturday                 */
#define FIRST_MISSING_DAY 639799 /* 3 Sep 1752                             */
#define NUMBER_MISSING_DAYS 11   /* 11 day correction during reformation   */

#define MONTHWID 24
#define J_MONTHWID 31

short LineWid = 80;                  /* Support for variable length widths */
short MonthWid = MONTHWID;           /* Julian calendars are 31 characters */
short columns = 1;                   /* 2 or 3 columns in year view        */

#define YEARWID (3*MonthWid-2)       /* width of yearly calendar           */
#define DAY_DESC (LineWid-MonthWid)  /* width of special day descriptions  */

#ifdef USE_COLOR                               /* define display attribute */
#define FG_BLACK     0x00                      /* possibilities.           */
#define FG_BLUE      0x01
#define FG_GREEN     0x02
#define FG_CYAN      0x03
#define FG_RED       0x04
#define FG_VIOLET    0x05
#define FG_ORANGE    0x06
#define FG_LTGRAY    0x07
#define FG_DKGRAY    0x08
#define FG_BRTBLUE   0x09
#define FG_BRTGREEN  0x0a
#define FG_BRTCYAN   0x0b
#define FG_BRTRED    0x0c
#define FG_BRTVIOLET 0x0d
#define FG_YELLOW    0x0e
#define FG_WHITE     0x0f
#define FG_FLASH     0x80
#define BG_BLACK     0x00
#define BG_BLUE      0x10
#define BG_GREEN     0x20
#define BG_CYAN      0x30
#define BG_RED       0x40
#define BG_VIOLET    0x50
#define BG_ORANGE    0x60
#define BG_WHITE     0x70

unsigned
char dfmon_attr   = FG_BLACK|BG_GREEN,   /* video attribute for month name */
     dfwk_attr    = FG_BLUE|BG_CYAN,     /* attribute for weekday header   */
     dfdy_attr    = FG_BLACK|BG_WHITE,   /* attribute for days             */
     dfsun_attr   = FG_VIOLET|BG_WHITE,  /* attribute for sundays          */
     dftoday_attr = FG_WHITE|BG_BLUE,    /* attribute for current day      */
     dfbk_attr    = FG_LTGRAY|BG_BLACK,  /* year calendar background       */
     dfspday_attr = FG_BRTCYAN|BG_BLACK, /* special day description attr.  */
     dfspdfl_attr = FG_BRTRED|FG_FLASH;  /* special day flasher            */
#ifdef USE_ANSI
char ansiterm_attr = FG_LTGRAY|FG_BLACK; /* ansiputs() terminator color    */
#endif

char *mon_attr, *wk_attr, *day_attr, *spclday_attr, *line_attr[MAXAPPTS];

/* By default we want colors under DOS and OS/2 but not UNIX */
#ifndef UNIX
int crt = 1;
#else
int crt = 0;
#endif

char *color_file = "cal.col";
#endif /* USE_COLOR */

char *data_file = "cal.dat";

#define REMINDER_FILE "dates"

short days[] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    thisday, thismonth, thisyear, discard_old = 0, prog_pause = 0,
    thismonth_only = 0, europe = 0, numfiles = 0, julian = 0,
    month3 = 0, year = 0, maxappts = 24, continu = 0;

char *months[] = {
     "",
     "January ", "February", "March", "April", "May", "June", "July",
     "August " , "September", "October", "November", "December" },
     USdays[] =     " Su Mo Tu We Th Fr Sa ",
     Europedays[] = " Mo Tu We Th Fr Sa Su ",
     j_USdays[] =     " Sun Mon Tue Wen Thu Fri Sat ",
     j_Europedays[] = " Mon Tue Wen Thu Fri Sat Sun ",
     *dayline = USdays,
     *filename[MAXFILES],
     homedir[CAL_MAXPATH],   /* home directory from argv[0] or enviornment */
     *line[MAXAPPTS],        /* line buffer for body of calendar           */
     *buf = NULL;

void  addfilename(char *);
void  clearfilenames(void);
void  printmonth (short, short);
short stryearlen(short);
char  *stryearcpy(char *, short);
void  fixtab(register short);
short day_in_year(short, short, short);
short day_in_week(short, short, short);
void  putattr(char *, register short);
void  setcolor(char);
void  ansiputs(char *, char *);
short specialdays(short, short);
short reminderdays(short, short);
FILE *efopen(const char *, const char *);
void  usage(void);

/* commandline argument list */
static struct arglist {
    char *opt;         /* full argument string */
    short needsvalue;  /* 1=argument needs a value, 0=stand-alone */
} opt[] = {
    { "3months",    0 },
    { "appts",      1 },
    { "data-file",  1 },
    { "europe",     0 },
    { "future",     0 },
    { "julian",     0 },
    { "monday",     0 },
    { "nodata",     0 },
    { "pause",      0 },
    { "thismonth",  0 },
    { "today",      0 },
    { "year",       0 },
    { "continue",   0 },
#ifdef USE_COLOR
    { "use-color",  0 },
    { "nocolor",    0 },
    { "color-file", 1 },
#endif
    { NULL,         0 }
};

/*===========================================================================
 * GETARG
 * Return the index of the argument in the option array.  val is set if the
 * argument needs a value.  The passed arg to test does not have to be
 * exactly like one of the arguments in o; it just has to match one of them
 * enough to be uniquely identified.  Any arg that is passed here should
 * begin with a '-' (or also a '/' if compiling for MSDOS or OS/2).
 *=========================================================================*/
int getarg(struct arglist *o, char *arg, char **val)
{
    int len = -1, i = -1, found = -1;
    *val = NULL;

    while (*arg == '-'
           #if (defined(MSDOS) || defined(OS2))
           || *arg == '/'
           #endif
        ) ++arg;
    while (arg[++len]) {
        arg[len] = tolower(arg[len]);
        if (arg[len] == '=') {
            arg[len] = '\0';
            *val = &arg[len+1];
            break;
        }
    }
    while (o[++i].opt) {
        if (!memcmp(o[i].opt, arg, len)) {
            if (found >= 0) return -1;
            found = i;
        }
    }
    if (found < 0) return -1;
    if (o[found].needsvalue && !(*val)) return -1;
    return found;
}

/*===========================================================================
 * setopt
 * This function will set a global option based on the value passed in.
 * The value passed in must be a valid index into the options array.
 *=========================================================================*/
void setopt(int c, char *optarg)
{
    switch (c) {
    case 0:
        month3 = 1; julian = 0; MonthWid = MONTHWID; break;
    case 1:
        maxappts = atoi(optarg); break;
    case 2:
        addfilename(optarg);
        break;
    case 3:
        europe = 1;  break;
    case 4:
        discard_old = 1; break;    /* show future dates only */
    case 5:
        MonthWid = J_MONTHWID; julian = 1; month3 = 0; break;
    case 6:
        europe = 1;  break;
    case 7:
        data_file = NULL; break;
    case 8:
        prog_pause = 1; break;
    case 9:
        thismonth_only = 1; break; /* show this month dates only */
    case 10:
        discard_old = 2; break;    /* show today's dates only */
    case 11:
        year = 1; break; /* show this year calendar */
    case 12:
        continu = atoi(optarg);    /* display successive months */
        if (continu > 0) maxappts = 8;
        break;
#ifdef USE_COLOR
    case 13:
        crt = 1; break;
    case 14:
        crt = 0; break;
    case 15:
        color_file = optarg; break;
#endif /* USE_COLOR */
    }
}

#ifdef NEEDS_STRNCASECMP
int strncasecmp(const char *s1, const char *s2, size_t n)
{
    char ss1, ss2;

    for (; 0 < n; ++s1, ++s2, --n) {
        ss1 = tolower(*s1);
        ss2 = tolower(*s2);
        if (ss1 != ss2)
            return (((unsigned char)ss1 < (unsigned char)ss2) ? -1 : +1);
        else if (ss1 == '\0')
            return 0;
    }
    return (0);
}
#endif

void text_init(void)
{
#ifdef HAVE_LOCALE_H
    int i, day;

    strcpy(dayline," ");
    for (i = 0; i < 7; i++) {
        if (europe)
            day = (i + 1) % 7;
        else
            day = i;
#ifdef HAVE_LANGINFO_H
        strncat(dayline,nl_langinfo(ABDAY_1+day),julian ? 3 : 2);
#else
        strncat(dayline,_time_info->abbrev_wkday[day],julian ? 3 : 2);
#endif
        strcat(dayline, " ");
    }

    for (i = 1; i <= 12; i++) {
#ifdef HAVE_LANGINFO_H
        months[i] = nl_langinfo(MON_1+i-1);
#else
        months[i] = _time_info->full_month[i-1];
#endif
    }
#else
    if (europe)
        dayline = julian ? j_Europedays : Europedays;
    else
        dayline = julian ? j_USdays : USdays;
#endif
}

/* When printing only one month, we sometimes need to really display
 * 3 months at a time if the user requested this.
 */
void processmonth(short m, short y)
{
    if (month3) {
        short prev_month, prev_year, next_month, next_year;

        if (m == 1) {
            prev_month = 12;
            prev_year = y - 1;
        }
        else {
            prev_month = m - 1;
            prev_year = y;
        }
        if (m == 12) {
            next_month = 1;
            next_year = y + 1;
        }
        else {
            next_month = m + 1;
            next_year = y;
        }
        columns = 3;
        fixtab (prev_year);
        printmonth (prev_month, prev_year);
        fixtab (y);
        printmonth (m, y);
        fixtab (next_year);
        printmonth (next_month, next_year);
    }
    else {
        fixtab (y);
        printmonth (m, y);
    }
}

/*===========================================================================
 * MAIN
 * Process command line, allocate and initialize, etc.
 *=========================================================================*/
#ifdef CONFIG_ORIG_CAL_MAIN_FUNCTION
int main(int argc, char *argv[])
{
    short       bufsiz, i, m, y;
    time_t      t;
    struct tm  *lt;
    int         c;
    char       *optarg;
    char       *calopt, *s;
    int         status=0;
    char        str[MAXLINE];
#ifdef USE_COLOR
    FILE *colorfile;
    short fg[8], bg[8];
#endif /* USE_COLOR */

#ifdef HAVE_LOCALE_H
    setlocale(LC_ALL, "");
#endif

    clearfilenames();

    /* First, set any options from the Env. Variable CALOPT */
    calopt = getenv("CALOPT");
    s = (calopt != NULL) ? s = strtok(calopt," ") : NULL;
    while (s != NULL) {
        if (*s != '-'
            #if (defined(MSDOS) || defined(OS2))
            && *s != '/'
            #endif
            ) break;
        if ((c = getarg(opt, s, &optarg)) < 0) {
            usage();
            status=1;   /* Let user known program didn't run */
            goto freestuff;
        }
        setopt(c, optarg);
        s = strtok(NULL," ");
    }

    /* Next, loop through command line options and set parameters */
    for (i = 1; i < argc; ++i) {
        if (*argv[i] != '-'
            #if (defined(MSDOS) || defined(OS2))
            && *argv[i] != '/'
            #endif
            ) break;
        if ((c = getarg(opt, argv[i], &optarg)) < 0) {
            usage();
            status=1;   /* Let user know program didn't run */
            goto freestuff;
        }
        setopt(c, optarg);
    }

#ifdef USE_COLOR
    /* If color is enabled, then double check to see if we are actually
     * displaying on a terminal.
     */
    if (crt)
        crt = isatty(fileno(stdout));
#endif /* USE_COLOR */

    if (maxappts < 8 || maxappts > MAXAPPTS) {
        usage();
        status=2;  /* Let user know failed because to many datafiles */
        goto freestuff;
    }

    if (!numfiles && data_file)  /* add default data file if none specified */
        addfilename(data_file);

    /* make the argument list compatible with unix cal */
    argc = argc - i + 1;
    for (m = 1; m < argc; ++m) argv[m] = argv[i++];

    /* Find out the line width of terminal and store this value. */
#ifdef MSDOS
    reg.h.ah = 0x0f;       /* function 0x0F of INT 0x10 - get display mode */
    int86(0x10, &reg, &reg);
    LineWid = max(80, reg.h.ah);  /* number of columns returned in AH */
    /* The above should work for all displays.
     * The following can be used instead, but will work in EGA and VGA only:*/
    /* Linewid = *((unsigned far *)0x004004a); */
#endif /* MSDOS */

    /* find originating directory */

#ifndef UNIX
    strncpy(homedir,argv[0],CAL_MAXPATH-1);
    homedir[CAL_MAXPATH-1] = 0; /* Just to be safe */
    i = strlen(homedir);
    while (i >= 0 && homedir[i] != '/' && homedir[i] != '\\' &&
           homedir[i] != ':')
        homedir[i--] = '\0';
#else
    s = getenv("HOME");
    strncpy(homedir,s,CAL_MAXPATH-1);
    homedir[CAL_MAXPATH-1] = 0; /* Just to be safe */
#endif /* UNIX */

    /* allocate workspace buffer */

    bufsiz = (maxappts)*LineWid + 2*DAY_DESC;
#ifdef USE_COLOR
    /* adjust workspace for color enhancements */
    bufsiz += (maxappts+2)*LineWid + YEARWID + (DAY_DESC+1);
#endif /* USE_COLOR */
    if ((buf = (char *)calloc(bufsiz,1)) == NULL) {
        puts("Memory overflow");
        goto freestuff;
    }

    /* assign pointers into buf */

    line[0] = buf;
    for (i = 1; i < maxappts; i++)
        line[i] = line[i-1] + LineWid;              /* calendar body    */

#ifdef USE_COLOR                                    /* color attributes */
    line_attr[0] = line[i-1] + LineWid;
    for (i = 1; i < maxappts; i++)
        line_attr[i] = line_attr[i-1] + LineWid;

    mon_attr = line_attr[i-1] + LineWid;
    wk_attr = mon_attr + YEARWID;
    day_attr = wk_attr + YEARWID;
    spclday_attr = day_attr + YEARWID;

    /* attempt to read in file of colors */
    if (crt && (colorfile = efopen(color_file, "r")) != NULL) {
        for (i = 0; i < 8; i++) {
            if (fgets(str, sizeof(str), colorfile) == NULL) break;
            if ((fg[i] = atoi(str)) == (bg[i] = atoi(&str[3]))) break;
            if (fg[i] > 15 || bg[i] > 15) break;
        }
        fclose(colorfile);
        if (i >= 8) {
            dfmon_attr   = fg[0] | (bg[0] << 4);
            dfwk_attr    = fg[1] | (bg[1] << 4);
            dfdy_attr    = fg[2] | (bg[2] << 4);
            dfsun_attr   = fg[3] | (bg[3] << 4);
            dftoday_attr = fg[4] | (bg[4] << 4);
            dfbk_attr    = fg[5] | (bg[5] << 4);
            dfspday_attr = fg[6] | (bg[6] << 4);
            dfspdfl_attr = fg[7] | (bg[7] << 4);
        }
    }

    /* initialize color attribute strings */
    memset (mon_attr, dfmon_attr, YEARWID);
    memset (wk_attr, dfwk_attr, YEARWID);
    memset (day_attr, dfdy_attr, YEARWID);
    memset (spclday_attr, dfspday_attr, DAY_DESC+1);
    spclday_attr[0] = dfspdfl_attr;
    for (i = MonthWid-2; i <= MonthWid+MonthWid; i += MonthWid) {
        memset (&mon_attr[i], dfbk_attr, 2);
        memset (&wk_attr[i], dfbk_attr, 2);
        memset (&day_attr[i], dfbk_attr, 2);
        memset (&day_attr[i - MonthWid + 3 + (6 * (julian ? 4 : 3) * europe)],
                dfsun_attr, julian ? 3 : 2);
    }
    memset (&day_attr[i - MonthWid + 3 + (6 * (julian ? 4 : 3) *europe)],
            dfsun_attr, julian ? 3 : 2);
#ifdef USE_ANSI
    ansiterm_attr = dfbk_attr;
#endif

#ifdef MSDOS
#ifndef USE_ANSI
    /* Find the start of video memory under DOS.  This is hardcoded
     * based on video mode.
     */
    int86(0x11, &reg, &reg);  /* read the equipment list into reg. */
    video = MK_FP(((reg.x.ax & 48) == 48) ? 0xb000 : 0xb800, 0);
#endif
#endif /* MSDOS */

#endif /* USE_COLOR */

    text_init();

    /* now that all the setup is done, we can begin with the program proper */

    t = time(NULL);
    lt = localtime(&t);
    thisyear = y = lt->tm_year + 1900;
    thismonth = m = lt->tm_mon + 1;
    thisday = lt->tm_mday;
    puts("");           /* first display a blank line */

    switch (argc) {
    case 1:             /* display current month if no arguments */
        if (!year)
            while (continu-- >= 0) {
                processmonth(m, y);
                if (++m > 12) { m = 1; ++y; }
            }
        else {
            /* "columns" tells the printmonth function that we are multiplexing
             * 2 or more months together before printing.  It implies that
             * appointments will not be displayed.
             */
            columns = julian ? 2 : 3;
            fixtab (thisyear);
            memset(str, ' ', YEARWID);
            stryearcpy(str+(YEARWID/2)-(stryearlen(thisyear)/2), thisyear);
            fputs(str, stdout);
            puts("\n");
            for (m = 1; m < 13; m++) printmonth (m, thisyear);
        }
        break;

    case 2:
        if (isdigit(argv[1][0]) || (isdigit(argv[1][1]) &&
                                    argv[1][0] == '-')) {
           /* "columns" tells the printmonth function that we are
            * multiplexing 2 or more months together before printing.
            * It implies that appointments will not be displayed.
            */
            columns = julian ? 2 : 3;
            fixtab (y = atoi(argv[1]));
            memset(str, ' ', YEARWID);
            stryearcpy(str+(YEARWID/2)-(stryearlen(y)/2), y);
            fputs(str, stdout);
            puts("\n");
            for (m = 1; m < 13; m++) printmonth (m, y);
            break;
        }
        /* drop through to next case */

    case 3:
        m = atoi(argv[1]);
        if (strlen(argv[1]) >= 3) {
            for (i = 1; i <= 12; i++) {
                strcpy(str, months[i]);
                if (!strncasecmp(argv[1], str, 3)) {
                    m = i;
                    break;
                }
            }
        }
        if (!m) {
            usage();
            status=3;   /* Let user know failed because invalid month */
            break;
        }
        if (argc == 3) {
            if (isdigit(argv[2][0]) || (isdigit(argv[1][1]) &&
                                        argv[2][0] == '-'))
                y = atoi(argv[2]);
            else {
                usage();
                status=4;  /* failed because invalid number parameters */
                break;
            }
        }
        while (continu-- >= 0) {
            processmonth(m, y);
            if (++m > 12) { m = 1; ++y; }
        }
        break;

    default:
        usage();
        status=4;  /* failed because invalid number parameters */
    }

    if (prog_pause) {
        fputs("\nPress the RETURN key to continue.", stderr);
        fflush(stdin);
        fgets(str, 3, stdin);
    }
freestuff:
    free(buf);
    return (status);
}
#endif // CONFIG_ORIG_CAL_MAIN_FUNCTION

/*===========================================================================
 * addfilename()
 * append a file name into the list of files to read
 * name must be a static string
 *=========================================================================*/
void addfilename(char *name)
{
    if (numfiles < MAXFILES && name) filename[numfiles++] = name;
}

/*===========================================================================
 * clearfilenames()
 * empty the list of file names
 * NOTE: does not free() any entries
 *=========================================================================*/
void clearfilenames(void)
{
    numfiles = 0;
}


/*===========================================================================
 * printmonth()
 * either prints an entire month at a time or multiplexes
 * a month into a buffer, dumping the buffer after the third call.
 *=========================================================================*/
void printmonth(short m, short y)
{
    register short first, last;
    register short index, p = 0;
    register char *ll;
    static short q = 0;
    short l, hilite = ((m == thismonth) && (y == thisyear)), num_appts = 0;

    if (columns > 1) {
        if (++q > columns) q = 1;
        p = MonthWid * (q - 1);   /* character position of line in buffer */

        if (q == 1) {
            memset(line[0], ' ', maxappts*LineWid);
            #ifdef USE_COLOR
            memcpy(line_attr[0], mon_attr, YEARWID);
            memcpy(line_attr[1], wk_attr, YEARWID);
            for (l = 2; l < 8; l++) memcpy(line_attr[l], day_attr, YEARWID);
            #endif /* USE_COLOR */
        }

        memset(line[0]+p, ' ', MonthWid);
        memcpy(line[0]+p+((MonthWid-2)/2)-(strlen(months[m])/2),
               months[m], strlen(months[m]));
        memcpy(line[1]+p, dayline, MonthWid-2);
    }
    else { /* Not printing multiple columns */
        /* initialize attribute buffers for month display */
#ifdef USE_COLOR
        for (l = 0; l < maxappts; l++) {
            if (l<1)
                memcpy(line_attr[l], mon_attr, MonthWid-1);
            else if (l<2)
                memcpy(line_attr[l], wk_attr, MonthWid-1);
            else if (l<8)
                memcpy(line_attr[l], day_attr, MonthWid-1);
            else
                memset(line_attr[l], 0, MonthWid-1);
            memcpy(&line_attr[l][MonthWid-1], spclday_attr, DAY_DESC+1);
        }

        memset(line[0], ' ', (maxappts)*LineWid);
        memcpy(line[0]+((MonthWid-2)/2)-((strlen(months[m])+1+stryearlen(y))/2),
               months[m], strlen(months[m]));
        stryearcpy(line[0]+((MonthWid-2)/2)-((strlen(months[m])+1
                   +stryearlen(y))/2)+strlen(months[m])+1, y);
        line[0][strlen(line[0])] = ' '; /* Remote NULL terminator */
        memcpy(line[1]+p, dayline, MonthWid-2);
#endif /* USE_COLOR */
    }

    if (y == 1752 && m == 9) {      /* special case Sep. 1752 */
        line[2][p + 8 - 3*europe] = '1';
        line[2][p + 11 - 3*europe] = '2';
        first = 14;
        last = 16 + europe;
        index = 12 - 3 * europe;
        if (julian) index += 4; /* account for extra space for julian dates */
    }
    else {
        /* day of week for first day of month */
        short dow = day_in_week(1, m, y);
        first = 1;
        last = 7 - dow;
        index = 3 * dow;
        if (julian) index += dow; /* Add extra space for julian dates */
    }

    for (l = 2; l < 8; ++l) {   /* loop thru month one week per line */
        ll = line[l] + p + 1;
        while (first <= last) { /* for each day in week encode day of month */
            if (julian) {
                short diy = day_in_year(first, m, y);
                ll[index+2] = '0' + diy % 10;
                diy /= 10;
                if (diy) ll[index+1] = '0' + diy % 10;
                diy /= 10;
                if (diy) ll[index] = '0' + diy % 10;
            }
            else {
                if (first >= 10) ll[index] = '0' + first / 10;
                ll[index+1] = '0' + first % 10;
            }
            if (columns == 1 && hilite && first == thisday) {
                /* hilight today */
#ifdef USE_COLOR
                line_attr[l][index] = line_attr[l][index+1] =
                line_attr[l][index+2] = line_attr[l][index+3] = dftoday_attr;
                if (julian) line_attr[l][index+4] = dftoday_attr;
#endif /* USE_COLOR */
#ifndef UNIX
                ll[index-1] = /* (crt) ? '\xde' : */ '<';
                ll[index+(julian ? 3 : 2)] = /* (crt) ? '\xdd' : */ '>';
#else
                ll[index-1] = '<';
                ll[index+(julian ? 3 : 2)] = '>';
#endif /* ! UNIX */
            }
            index += 3;
            if (julian) index++;
            ++first;
        }
        last = (last + 7) > days[m] ? days[m] : last + 7;
        index = 0;
    }

    if (columns == 1) {
        num_appts = specialdays(m, y);
        #ifdef USE_REMINDER
        if (num_appts < 1)
            num_appts = reminderdays(m, y);
        #endif
    } /* end of not multi-column */

    /* Force num_appts to be eight at minimum so that the day lines will
     * always be printed out (extra important for multi-column mode).
     */
    num_appts = max(8, num_appts);
    for (l = 0; l < num_appts; l++) {
        if (columns == 1 || q == columns) {
            index = LineWid-1;
            ll = line[l];
            while (index >= 1 && ll[index] == ' ') --index;
            if (q == columns)
                index = MonthWid*columns-3;
            /* leave one space after last day in week */
            else if (index < MonthWid-1)
                index = MonthWid-1;
            ll[index+1] = '\0';
            #ifdef USE_ANSI
            ansiputs(line[l],line_attr[l]);
            #else
            puts(ll);
            #ifdef USE_VIDEORAM
            putattr(line_attr[l], (columns > 1) ? MonthWid*columns-3 : LineWid-1);
            #endif /* USE_VIDEORAM */
            #endif /* !USE_ANSI */
        }
    }
    #ifdef USE_ANSI
    setcolor(0);
    #endif
}

short stryearlen(short year)
{
    short yl = 0;
    short neg = (year < 0);

    if (neg) year = -year;
    do {
        yl++;
        year = year / 10;
    } while (year);

    if (neg)
        yl++;

    return yl;
}

char *stryearcpy(char *dest, short year)
{
    char str[11], *p;
    short neg = (year < 0);

    p = str+10;
    *p = '\0';

    if (neg) year = -year;
    do {
        --p;
        *p = '0' + year % 10;
        year = year / 10;
    } while (year);

    if (neg)
        *(--p) = '-';

    strcpy(dest, p);
    return dest;
}

/* Before 1753, a leap year was simply every 4 years.  After 1752, its
 * every 4 years unless it falls on a century.  On century bounderies
 * its only counted every 4 centuries.
 */
#define is_leap_year(y) \
    ((y) <= 1752 ? !((y) % 4) : \
    (!((y) % 4) && ((y) % 100)) || !((y) % 400))

#define centuries_since_1700(y) \
    ((y) > 1700 ? (y) / 100 - 17 : 0)

#define quad_centuries_since_1700(y) \
    ((y) > 1600 ? ((y) - 1600) / 400 : 0)

#define leap_years_since_year_1(y) \
    ((y) / 4 - centuries_since_1700(y) + quad_centuries_since_1700(y))

/*===========================================================================
 * fixtab() - correct for leapyears.
 *=========================================================================*/
void fixtab(short y)
{
    if (is_leap_year(y)) {
        days[2] = 29;
    }
}

/*===========================================================================
 * day_in_year
 *     return the 1 based day number within the specified year
 *============================================================================
 */
short day_in_year(short d, short m, short y)
{
    int i;

    for (i = 1; i < m; i++) {
        if (i == 2)
            d += (is_leap_year(y)) ? 29 : 28;
        else
            d += days[i];
    }
    return d;
}

/*===========================================================================
 * day_in_week
 *      return the 0 based day number for any date from 1 Jan. 1 and
 *      beyond.  Assumes the Greogorian reformation eliminates 3 Sep. 1752
 *      through 13 Sep. 1752.  Returns Thursday for all missing days.
 *=========================================================================*/
short day_in_week(short d, short m, short y)
{
    long total_days;

    /* Calculate total number of days since year 1 for past years
     * ignoring leap years.  Then add in leapyears.  Then add in
     * total number of days that have pasted this year.
     */
    total_days = (long)(y - 1) * 365 + leap_years_since_year_1(y - 1)
                 + day_in_year(d, m, y);

    /* If day falls before 3 Sep. 1752, day of week we mod by 7 to see
     * how many weeks have passed.  1 Jan. 1 started on a saturday so
     * take acount of that by adding that number of days to count.
     */
    if (total_days < FIRST_MISSING_DAY)
        return ((total_days - 1 + SATURDAY - europe) % 7);
    if (total_days >= (FIRST_MISSING_DAY + NUMBER_MISSING_DAYS))
        return (((total_days - 1 + SATURDAY - europe)
                 - NUMBER_MISSING_DAYS) % 7);
    return (THURSDAY - europe);
}


#ifdef USE_VIDEORAM
/*===========================================================================
 * putattr() - MSDOS or OS/2 only
 * modify the video memory text attribute areas with the attributes passed
 * in attr of lengh len, starting at the current cursor location.
 *=========================================================================*/
void putattr(char *attr, register short len)  /* write video attr. string */
{
#ifdef OS2
    USHORT row, col;
    int i;
#endif /* OS2 */

    if (!crt) return;

#ifdef OS2
    VioGetCurPos(&row, &col,0);
    --row;
    while (len) {        /* minimize the number of Vio calls */
        for (i = 1; i < len; i++)
            if (attr[i] != *attr) break;
        VioWrtNAttr((PBYTE) attr, i, row, col, 0);
        attr += i; col += i; len -= i;
    }

#else /* if !OS2 */

    reg.h.ah = 3;
    reg.h.bh = 0;
    int86(0x10, &reg, &reg);
    tmpvideo = video + ((LineWid << 1) * (reg.h.dh - 1) + reg.h.dl + 1);
    while (len--) {
      #ifdef __DJGPP__
        _farpokeb(_dos_ds, tmpvideo, *(attr++));
      #else
        *tmpvideo = *(attr++);
      #endif
      tmpvideo += 2;
    }
#endif /* !OS2 */
}
#endif /* USE_VIDEORAM */


#ifdef USE_ANSI
/*===========================================================================
 * ansiputs()
 * Puts a string to stdio in color as defined by line_attr.
 *=========================================================================*/
void ansiputs(char *l, char *a)
{
    char prev_color;

    setcolor(*a);
    while (*l) {
        fputc(*l++,stdout);
        prev_color = *a++;
        if (prev_color != *a) setcolor(*a);
    }
    setcolor(ansiterm_attr);
    fputc('\n',stdout);
}


/*===========================================================================
 * setcolor()
 * Set the color attributes to those passed in.
 *=========================================================================*/
void setcolor(char attr)
{
    char command[256];
    char dos2ansi[] = { 0, 4, 2, 6, 1, 5, 3, 7, 0, 4, 2, 6, 1, 5, 3, 7};
    if (!crt) return;

    /* ANSI codes
       0 = normal attributes (white one black)
       1 = high intensity     5 = blinking
       2 = Normal intensity   7 = reverse
       4 = underlined         8 = invisible
     */
    if (attr == 0)
        fputs("\033[0m",stdout);
    else {
        strcpy(command,"\033[0;");
        if (attr&0x80) strcat(command,"5;");
        if (attr&0x08) strcat(command,"1;");
        sprintf(command,"%s3%d;4%dm",command,dos2ansi[attr&0x0F],
                dos2ansi[(attr&0x70)>>4]);
        fputs(command,stdout);
    }
}
#endif /* USE_ANSI */


/*============================================================================
 * add_days()
 * function to return year, month, day of dates + n days
 * used in find periodic dates.
 * e.g. 1996 02 06 14 -- Payday! --
 *==========================================================================*/
void add_days(short *y, short *m, short *d, short n)
{
    short tmpfeb = days[2];
    days[2] = is_leap_year(*y) ? 29 : 28;
    *d += n;
    while (*d > days[*m]) {
        *d -= days[*m];
        if (++(*m) > 12) {
            ++(*y);
            days[2] = is_leap_year(*y) ? 29 : 28;
            *m = 1;
        }
    }
    days[2] = tmpfeb;  /* restore original value */
}

/* Returns the day for the given year and month that the nth day-of-week
 * occurs on.
 */
int nth_weekday(int y, int m, int n, int dow)
{
    int first_dow;
    int day;
    int weeks_counted = 0;
    int days_in_month;

    if (m == 2)
        days_in_month = is_leap_year(y) ? 29 : 28;
    else
        days_in_month = days[m];

    first_dow = day_in_week(1, m, y);

    /* If looking for something that occurs during first week,
     * calulate date now and return it.
     */
    if (n == 1 && dow >= first_dow) {
        day = first_dow - dow + 1;
        return day;
    }

    /* For other cases, record the number of days left week */
    day = 7 - first_dow;

    /* Record if we've detected a week that has dow in it */
    if (dow >= first_dow) weeks_counted++;

    while (weeks_counted < n) {
        /* Check to see if next week will contain the dow we are looking
         * for.  If not then get out of loop.
         */
        if (day + dow + 1 > days_in_month) break;

        weeks_counted++;
        if (weeks_counted < n) day += 7;
    }

    /* Unless user asked to return the last occurance of that dow (9)
     * then check for error case and return that fact.
     */
    if (n != 9 && weeks_counted != n) return -1;

    day += dow + 1;
    return day;
}

/* make space for a new item in the right spot & return pointer to it */
char *insertitem(char **lln, int maxentry, int dy)
{
    short j,k,day;

    for (j = 0; j < maxentry; j++)              /* insert in sorted order */
        if (dy < (day = atoi(&lln[j][1]))) {
            k = maxentry;
            if (k == maxappts) --k;
            for (; k > j; k--)                  /* move everything up     */
                strcpy(lln[k], lln[k-1]);
            break;
        }
        else if (day == 100) dy = dy-100;       /* reached new month      */

    if (j == maxappts) return NULL;
    return lln[j];
}

/*===========================================================================
 * specialdays()
 * find the file CAL.DAT and attempt to read in special date descriptions.
 * e.g. -999 12 25 00 Christmas Day
 * Yes, this is a spaghetti-code patch on top of a rather elegant calander
 * display program.  Good luck understanding it; it's a mess, but it works.
 *=========================================================================*/
short specialdays(short m, short y)
{
    FILE   *fp;
    short  mo, dy, yr, w, n, filenum, wn, weeklyflag, periodflag = 0, k, j,
           hiappt = 1, hilight = (m == thismonth && y == thisyear);
    char **lln = NULL, *ll;
    char str[MAXLINE];

    if ((lln = (char **)calloc(maxappts+1, sizeof(char *)))==NULL)
        goto spcldone;

    if (m != thismonth) discard_old = 0;
    /* Special day descriptions are copied directly into line
     * buffer, at an offset of MonthWid.
     */
    for (j = 0; j < maxappts; j++) lln[j] = &line[j][MonthWid-1];

    strcpy(lln[0], " 100");             /* last (hiappt) entry */

    for (filenum = 0; filenum < numfiles; filenum++) {
        if ((fp = efopen(filename[filenum], "r")) == NULL) continue;

        while (fgets(str, sizeof(str), fp) != NULL) {  /* go until EOF is hit */
            if (!isdigit(*str) && *str != '-') continue; /* a data line? */
            if ((yr = atoi(str)) == 0) continue;         /* get year */
            if ((mo = atoi(&str[5])) == 0) continue;     /* get month */
            dy = atoi(&str[8]);                          /* get day */
            wn = atoi(&str[11]);                         /*nth wkdy or period*/

            /* Must have either day or weekday set */
            if (!dy && !wn)
                continue;

            /* Currently, don't support periodically-recurring dates
             * that occur in next month/year.  The following stops
             * that processing from happening.
             */
            if (yr == y && mo > m && dy > 0 && wn > 0)
                continue;

            /* If currenty entry is a periodically-recurring date then
             * continue processing.
             * If current entry is for every year or current year, and
             * the month is for this month, continue processing.
             * If this month is december and the year is for every
             * year or next year, then continue processing if entry
             * is for january of next year.
             */
            if (!( (yr >= 1970 && mo > 0 && dy > 0 && wn > 0) ||
                   ((yr == -999 || yr == y) &&
                    (mo == m || mo == m+1)) || /* got it all? */
                   ((yr == -999 || yr == y+1) &&
                    (mo == 1 && m == 12)) || mo == -9))
                continue;

            /* Check for daily reminders and force entry to look like
             * it happens today as long as we are displaying a calendar
             * for the real this month and this year.
             */
            if (dy == -9) {
                if (m == thismonth && y == thisyear)
                    dy = thisday;            /* set daily reminder */
                else
                    continue;
            }

            /* Skip entries that are not for month to be displayed if user
             * request that.
             */
            if (discard_old == 2 &&
                mo != thismonth && dy != thisday && yr != thisyear)
                continue;

        periodduplicate:
            if (yr >= 1970 && mo > 0 && dy > 0 && wn > 0  /* proper format? */
                && !(yr == thisyear && mo == thismonth &&
                     dy == thisday && !periodflag)     /* not today? */
                && yr <= y && !(yr == y && mo > m)) {  /* <= displayed month
                                                               & year? */
                while (yr < y || mo <= m) {   /* find periodic dates */
                    add_days(&yr, &mo, &dy, wn);
                    if (yr == y && mo == m) break;
                }
                if (mo > m) continue;
                /* periodic dates left in month */
                periodflag = (days[m] - dy)/wn;
                if (periodflag && ((discard_old && dy<thisday) || (discard_old==2 && dy!=thisday)))
                    goto periodduplicate;
            }
            else periodflag = 0;

            weeklyflag = 5*(wn<0 && wn!=-9); /* flag to dup. weekly dates */

            if (wn < 0) wn = 50-wn;
        weeklyduplicate:
            w = weeklyflag ? weeklyflag : wn/10;

            /* Make sure its no a period-recurring date */
            if (!(yr > 0 && mo > 0 && dy > 0) &&
                ((wn >= 11 && wn <= 57) || w == 9) && (mo == m || mo == -9)) {
                /* find nth weekday */
                n = wn%10 - 1;          /* day of week (0=sun, 1=mon, etc.) */
                if (n < 0 || n > 6) continue;

                if ((dy = nth_weekday(y,m,w,n)) < 0) {
                    if (--weeklyflag > 0) goto weeklyduplicate;
                    else continue;        /* nth weekday didn't exist */
                }
            }

            if (!dy || (mo > 0 && dy > days[mo]))
                continue;        /* next loop if wn>57 or wn<11 or dy=0 */
            if ((mo == m+1 && (yr == y || yr == -999))
                || (mo == 1 && m == 12 && (yr == y+1 || yr == -999)))
                   dy += 100;       /* make sure 'next month' days are last */

            if ((discard_old && dy<thisday) || (discard_old==2 && dy != thisday))
                continue;            /* next loop if old day */
            if (thismonth_only && dy >= 100) continue;

            if ((ll = insertitem(lln,hiappt,dy)) == NULL) continue;
            ll[0] = (hilight && dy == thisday && (mo == m || mo == -9))
                ? '*' : ' ';  /* 'today' flag */
            ll[1] = (dy%100 < 10) ? ' ' : '0' + (dy%100)/10;
            ll[2] = '0' + dy%10;
            ll[3] = ':';
            j = strlen(str) - 1;         /* get rid of trailing white space */
            while (j >= 13 && isspace(str[j])) str[j--] = '\0';

/*===========================================================================
 *             Check for special case of Anniversary/Birthdays
 *   Change added by R. Scott, and generalized a bit by Alex Matulich
 * A field indicated by [] will be displayed with [], but a field using {}
 * will be displayed without the braces.
 *===========================================================================
 * These changes replace the next two lines:
 *    str[j = 14+DAY_DESC-6] = '\0';
 *    strcpy(&ll[4], &str[13]);
 *===========================================*/

            j=13; k=4;  /* init pointers into strings */
            while (k < DAY_DESC - 1 && str[j]) {
                ll[k++] = str[j];
                if (str[j] == '\\') { /* Don't treat next char as special */
                    ll[k-1] = str[++j]; /* Write next char over '\' */
                    j++;                /* & then advance to next char */
                }
                /* start of [field] */
                else if (str[j] == '[' || str[j] == '{') {
                    short suffix = -1;   /* <0 indicates no ordinal suffix */
                    long ipower = 1,
                        by = atoi(&str[++j]); /* year of aniversary */
                    if (by <= y) {             /* will year be modified? */
                        by = y - by + (dy>100 && mo==1); /* years since anniversary */
                        if (str[j-1] == '{')
                            suffix = by; /* ordinal suffix will be attached */
                    }
                    if (str[j-1] == '{' || str[j-1] == '[')
                        --k;  /* don't display brace */
                    while (by / ipower) ipower *= 10L;
                    ipower /= 10L;      /* ipower is now the magnitude of by */
                    if (!by) ll[k++] = '0';
                    else while (ipower && k < DAY_DESC - 1) {
                        ll[k++] = by / ipower + '0';
                        by -= (by / ipower) * ipower;/* remove largest digit */
                        ipower /= 10L;
                    }
                    /* optionally add the ordinal suffixes st, nd, rd and th
                     * to the end of value for better readability (for example,
                     * 31 will be 31st, 23 will be 23rd, etc.) */
                    if (suffix >= 0 && k < DAY_DESC - 3) {
                        suffix %= 100;  /* only use last two digits */
                        if (suffix >= 11 && suffix <= 13) suffix = 4;
                        else suffix %= 10; /* last digit */
                        switch (suffix) {
                        case 1:  ll[k++]='s'; ll[k++]='t';  break;
                        case 2:  ll[k++]='n'; ll[k++]='d';  break;
                        case 3:  ll[k++]='r'; ll[k++]='d';  break;
                        default: ll[k++]='t'; ll[k++]='h';
                        }
                    }
                    while (isdigit(str[j])) ++j;  /* advance to end of field */
                    if (str[j] == '}' || str[j] == ']') ++j; /* skip brace*/
                }
                else
                    ++j;      /* advance to next char */
            }
            ll[k] = '\0';   /* ensure string is terminated */
/*===========================================================================
 * End of anniversary changes
 *=========================================================================*/

            if (++hiappt > maxappts) hiappt = maxappts;
            if (--weeklyflag > 0) goto weeklyduplicate; /* dup. wkly reminders */
            if (periodflag > 0) goto periodduplicate; /* dup. periodic reminders */
        }

        fclose(fp);
    }

    for (j = 0; j < hiappt; j++)
        if (atoi(&lln[j][1]) == 100) break;     /* find last item */
    if (j == hiappt-1)
        lln[--hiappt][0] = '\0';
    else if (j < hiappt)
        strcat(strcat(strcpy(lln[j], " "), months[(m%12)+1]), "--");

spcldone:
    free(lln);
    return hiappt;
}


#ifdef USE_REMINDER

/* dayofweek()
 * convert Sun, Mon, Tues, etc. to number (honours europe flag)
 * returns 0 in case of error
*/
int dayofweek(const char *day)
{
    switch (toupper(day[0])) {
    case 'S':
        if (tolower(day[1]) == 'u')
            return europe ? 7 : 1;
        else
            return 7 - europe;
    case 'M':
        return 2 - europe;
    case 'T':
        if (tolower(day[1]) == 'u')
            return 3 - europe;
        else
            return 5 - europe;
    case 'W':
        return 4 - europe;
    case 'F':
        return 6 - europe;
    default:
        return 0;
    }
}


/*===========================================================================
 * reminderdays()
 * find the file DATES and attempt to read in reminder-style date descriptions.
 * e.g. 12/25:7:Christmas Day::N
 *=========================================================================*/
short reminderdays(short m, short y)
{
    FILE *fp;
    short mo, dy, yr, n, wn, weeklyflag, filenum, j, hiappt = 1,
        hilight = (m == thismonth && y == thisyear);
    char **lln = NULL, *ll;
    char *descrip;
    static char tempstr[MAXLINE];   /* big enough for a long reminder line */

    if (!data_file) return 0;   /* don't read any data files */
    if ((lln = (char **)calloc(maxappts+1, sizeof(char *)))==NULL) return 1;

    /* Special day descriptions are copied directly into line
     * buffer, at an offset of MonthWid.
     */
    for (j = 0; j < maxappts; j++) lln[j] = &line[j][MonthWid-1];

    strcpy(lln[0], " 100");     /* last entry */

    if (m != thismonth) discard_old = 0;

    clearfilenames();   /* ignore all the cal native format data files */
    addfilename(REMINDER_FILE);
    for (filenum = 0; filenum < numfiles; filenum++) {
        if ((fp = efopen(filename[filenum], "r")) == NULL) continue;

        /* go until EOF is hit */
        while (fgets(tempstr, sizeof(tempstr), fp) != NULL) {
            if (isspace(tempstr[0]))
                continue;  /* ignore blanks and empty lines */
            else if (strchr(tempstr, ':') &&
                     (isdigit(tempstr[0]) || (tempstr[1] != ':'))) {
                /* assume normal date entry & not include file (which may be
                   of form C:\NAME)  */

                char *field = strtok(tempstr, ":");             /* get date */

                if (isdigit(field[0])) {
                    mo = yr = wn = 0;
                    /* day of month only? */
                    dy = atoi(tempstr);
                    if ((field = strchr(field,'/')) != NULL) {
                        /* mm/dd or mm/dd/yy format */
                        mo = dy;
                        if (mo != m)            /* not this month */
                            continue;
                        dy = atoi(field+1);
                        yr = 0;

                        if ((field = strchr(field+1,'/')) != NULL) {
                            /* mm/dd/yy format */
                            yr = atoi(field+1);
                            if (yr < 1000) yr = yr + 1900;
                        }
                    }
                    if ((dy > 31))              /* bad day */
                        continue;
                    if (yr && (yr != y))        /* not this year */
                        continue;

                } else {
                    /* day of week */
                    dy = mo = yr = 0;
                    wn = dayofweek(field);
                }

                strtok(NULL, ":");              /* skip days of notice */
                descrip = strtok(NULL, ":");    /* get description */
                /* get person & status fields */
                if ((field = strtok(NULL, "\n")) == NULL)
                    continue;           /* skip if sanity check fails */
                if (field[0] != ':') {          /* person is specified */
                    char *newdescrip = malloc(LineWid);
                    field = strtok(field, ":"); /* get person */
                    strcat(strcat(strcpy(newdescrip, field), "'s "), descrip);
                    /* BUG: could overwrite end by 1 char */
                    strcpy(descrip, newdescrip);
                    field = strtok(NULL, ":");  /* get status */
                    free(newdescrip);
                } else ++field;

                if (!field || field[0] == 'D')  /* do not report this event */
                    continue;

            } else {
                /* must be an include file--add to the list to check */
                /* NOTE: this malloced storage is never freed */
                addfilename(strtok(strcpy(malloc(strlen(tempstr)+1),tempstr),"\n"));
                continue;
            }

            weeklyflag = 5*(wn>0);       /* flag to dup. weekly dates */

            do {
                if (!(yr > 0 && mo > 0 && dy > 0) &&
                    (wn >= 1) && (mo == m || mo <= 0)) {
                    n = wn - 1;         /* day of week (0=sun, 1=mon, etc.) */
                    if ((dy = nth_weekday(y,m,weeklyflag,n)) < 0) {
                        if (--weeklyflag > 0) continue;
                        else continue;        /* nth weekday didn't exist */
                    }
                }

                if (!dy) continue;             /* ignore if dy=0 */
                if (discard_old < 2 && ((mo == m+1 && (yr == y || yr <= 0))
                    || (mo == 1 && m == 12 && (yr == y+1 || yr <= 0))))
                    dy += 100;      /* make sure 'next month' days are last */

                if ((discard_old && dy<thisday) || (discard_old==2 &&
                    (dy != thisday || mo != thismonth || yr != thisyear)))
                    continue;  /* next loop if old day */

                if ((ll = insertitem(lln,hiappt,dy)) == NULL) continue;
                ll[0] = (hilight && dy == thisday && (mo == m || mo == -9))
                    ? '*' : ' ';  /* 'today' flag */
                ll[1] = (dy%100 < 10) ? ' ' : '0' + (dy%100)/10;
                ll[2] = '0' + dy%10;
                ll[3] = ':';
                j = strlen(descrip) - 1;  /* get rid of trailing white space */
                while (j > 0 && isspace(descrip[j])) descrip[j--] = '\0';

                descrip[DAY_DESC-5] = '\0';     /* truncate description */
                strcpy(&ll[4], descrip);

                if (++hiappt > maxappts) hiappt = maxappts;
            } while (--weeklyflag > 0); /* dup. weekly reminders */
        }
        fclose(fp);
    }

    for (j = 0; j < hiappt; j++)
        if (atoi(&lln[j][1]) == 100) break;     /* find last item */
    if (j == hiappt-1)
        lln[--hiappt][0] = '\0';
    else if (j < hiappt)
        strcat(strcat(strcpy(lln[j], " "), months[m%12]), "--");

    free(lln);
    return hiappt;
}
#endif /* USE_REMINDER */


/*===========================================================================
 * efopen() - fopen() replacement that does path searches
 *=========================================================================*/
FILE *efopen(const char *file, const char *mode)
{
    FILE  *fp;
    char str[CAL_MAXPATH];

#ifdef OS2
    char  path[CAL_MAXPATH];
#endif /* OS2 */

    /* Attempt to open file using exact name passed in */
    if ((fp = fopen(file, mode)) == NULL) {
        /* If not found and we know the users home directory then
         * look there.  Need to sanitize the filename though.
         */
        if (*homedir && strlen(homedir) < CAL_MAXPATH) {
            strcpy(str, homedir);
            if ((strlen(homedir) + strlen(file) + 1) < CAL_MAXPATH) {
#ifdef UNIX
                if (homedir[strlen(homedir)-1] != '/') strcat(str,"/");
                if (file[0] != '.') strcat(str, ".");
#else
                if (homedir[strlen(homedir)-1] != '/') strcat(str,"\\");
#endif
                strcat(str, file);
                fp = fopen(str, mode);
            }
        }

#ifdef OS2
        if (fp == NULL) {
            _searchenv(file, "PATH", path);
            if (*path == '\0')
                _searchenv(file, "DPATH", path);
            if (*path)
                fp = fopen(path, mode);
        }
#endif /* OS2 */

        /* If still not found then look in a hardcoded path */
        if (fp == NULL) {
#ifdef PREFIX
            strcpy(str, PREFIX);
#else
            /* Note the unix style path; Under DOS/OS/2 you better
             * define PREFIX to prevent this from being used!
             */
            strcpy(str, "/ect/cal/");
#endif
            if (strlen(str) + strlen(file) <= CAL_MAXPATH) {
                strcat(str,file);
                fp = fopen(str, mode);
            }
        }
    }
    return fp;
}


/*===========================================================================
 * usage() - called from main() - display commandline usage
 *=========================================================================*/
void usage()
{
fputs("\n\
cal 4.0 - Display a monthly or yearly calendar, with optional appointments.\n\n\
Usages:  cal [options] [[1|2|3|...|12] year]\n\
         cal [options] [jan|feb|mar|...|dec] [year]\n\n\
Options:\n\
  --3[months]         Display prev/current/next month\n\
  --a[ppts]=n         Display maximum of n (8-50) appointments (24)\n\
  --con[tinue]=n      Display successive months n times after the first\n\
  --d[ata-file]=file  Load appointments from `file'\n\
                      (default: ",stderr);

#ifdef PREFIX
fputs(PREFIX, stderr);
#else
fputs("/etc/cal/", stderr);
#endif

#ifndef UNIX
fputs("cal.dat)\n", stderr);
#else
fputs("cal.dat, $HOME/.cal.dat)\n", stderr);
#endif

fputs("\
  --e[urope]          European format (first day is Monday)\n\
  --f[uture]          Show only future appointments on current month\n\
  --j[uian]           Display Julian dates (days numbered from 1 January\n\
  --m[onday]          Display Monday as first day of week (same as --europe)\n\
  --nod[ata]          Ignore appointment descriptions file\n\
  --p[ause]           Pause for keystroke before exiting\n\
  --th[ismonth]       Show only current month appointments\n\
  --to[day]           Show only today's appointments on current month\n\
  --y[ear]            Display a calendar for the current year\n", stderr);

#ifdef USE_COLOR
fputs("\
  --u[se-color]       Allow use of colors\n\
  --noc[olor]         Inhibit the use of colors\n\
  --col[or-file]=file Load color definitions from `file'\n\
                      (default: ",stderr);

#ifdef PREFIX
fputs(PREFIX, stderr);
#else
fputs("/etc/cal/", stderr);
#endif

#ifndef UNIX
fputs("cal.col)\n", stderr);
#else
fputs("cal.col, $HOME/.cal.col)\n", stderr);
#endif
#endif /* USE_COLOR */

fputs("\n(c) 1992-2002 A. Matulich, Unicorn Research Corporation\n\
http://unicorn.us.com\n", stderr);
}
