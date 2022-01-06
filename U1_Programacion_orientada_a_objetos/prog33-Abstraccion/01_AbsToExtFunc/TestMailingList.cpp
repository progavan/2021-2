/** TestMailingList.cpp */
#include <stdio.h>
#include <string.h>
#include "BaseMailingListEntry.h"
#include "FileMailingListEntry.h"
#include "CommandLineMailingListEntry.h"

void ProcessEntries( BaseMailingListEntry *pEntry )
{
 bool not_done = pEntry->First();
 while ( not_done )
 {
   // Do something with the entry here.
   // Get the next one
   not_done = pEntry->Next();
 }
}

/** REF.: Brian W. Kernighan, Dennis M. Ritchie,
 * The ANSI C Programming Language,
 * page 30. Brian W. Kernighan, Dennis M. Ritchie -
 * The ANSI C Programming Language-Prentice Hall (1988).pdf
 * getline: read a line into s, return length.
 */
int KnR_getline(char s[],int lim)
{
 int c, i;
 for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
   s[i] = c;
 if (c == '\n') {
   s[i] = c;
  ++i;
 }
 s[i] = '\0';
 return i;
}


int main(int argc, char **argv)
{
 int choice = 0;
#if 1 // LMC 2021.12.26
 char linea[MAXLINE];
#endif
 printf("Enter 1 to use a file-based mailing list\n");
 printf("Enter 2 to enter data from the command line\n");
#if 0 // LMC 2021.12.26
 scanf("%d", &choice );
#else
 scanf("%d%*c", &choice );
#endif
 if ( choice == 1 )
 {
   char szBuffer[ 256 ];
   printf("Enter the file name: ");
  #if 0 //LMC 2021.12.25
   gets(szBuffer);
  #else
   KnR_getline(linea,MAXLINE);
   strcpy(szBuffer,linea);
   // Remove trailing carriage return
   szBuffer[strlen(szBuffer)-1] = 0;
  #endif
   FileMailingListEntry fmle(szBuffer);
   ProcessEntries( &fmle );
 }
 else
 if ( choice == 2 )
 {
   CommandLineMailingListEntry cmle;
   ProcessEntries( &cmle );
 }
 else
   printf("Invalid option\n");
 return 0;
}/*end main()*/

