/*#include <ctime>*/ // if working with C++
#include <time.h>    // if working with C
/**
 *time_t now = time(0);
 *tm *ltm = localtime(&now);
 */
typedef struct tm tm;

int get_year(tm* ltm){
  return 1900+ltm->tm_year;
}

int get_month(tm* ltm){
  return 1+ltm->tm_mon;
}

int get_day(tm* ltm){
  return ltm->tm_mday;
}

int get_hour(tm* ltm){
#if 0//LMC Vease 2022-03-11_23-09wtf.png
  return 1+ltm->tm_hour;
#else
  return ltm->tm_hour;
#endif
}

int get_min(tm* ltm){
#if 0//LMC 2022.03.11, Vease 2022-03-11_23-04wtf.png
  return 1+ltm->tm_min;
#else
  return ltm->tm_min;
#endif
}

int get_sec(tm* ltm){
#if 0//LMC 2022.03.11
  return 1+ltm->tm_sec;
#else
  return ltm->tm_sec;
#endif
}


