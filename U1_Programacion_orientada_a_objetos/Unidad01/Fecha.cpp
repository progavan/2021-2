#include <vector>
#include "Fecha.h"
#if 0//LMC 2022.03.04
#include "util.h"
#else
#include "Unidad01_util.h"
#endif // 0

short Fecha :: operator-(Fecha& f){
 Day_in_year=day_in_year((short)d,(short)m,(short)a);
 f.Day_in_year=day_in_year((short)f.d,(short)f.m,(short)f.a);
 return Day_in_year-f.Day_in_year;
}

