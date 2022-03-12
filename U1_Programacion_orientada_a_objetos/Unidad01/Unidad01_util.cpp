/**Unidad01_util.cpp*/
#include <cstdio>
#include <ctime>
#include "Unidad01_util.h"
#include "gettingdate.h"
#include "Unidad01_util.h"
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

/** last_five_days_diff
 * calcula la longitud en d\'ias de un intervalo que
 * contiene las 5 fechas m\'as recientes contenidas
 * en el vector std::vector<Fecha> vdf
 * pre: el vector vdf contiene al menos 5 fechas.
 * pre: las 5 fechas m\'as recientes en el vector vdf
 *      son del mismo a\~{n}o.
 */
short last_five_days_diff(std::vector<Fecha> vdf)
{
 ordenar_fechas(vdf);
 Fecha f1 = vdf[vdf.size()-5],f2 = vdf[vdf.size()-1];
 return f2 - f1;
}
/** print_ident_data(__FILE__,argv[0]); en la funci\'on
 * main imprime datos de identificaci\'on: del archivo
 * fuente que contiene la funci\'on main, y el nombre
 * del archivo ejecutable.
 */
void
print_ident_data(const char *source,char *exe)
{
 printf("FUENTE: %s\n",source);
 printf("EJECUTABLE: %s\n",exe);
}

/**Becomed a friend function of class Calendario on 2022.03.11*/
void print_ident_data_cpp(const char *source,const char *exe)
{
 int dia,mes,anyo;
 time_t now = time(0);
 tm *ltm = localtime(&now);
 anyo = get_year(ltm);
 mes = get_month(ltm);
 dia = get_day(ltm);
 Fecha today(dia,mes,anyo);
 Calendario *Cal_Greg = new Calendario(anyo);
 printf("%s %2d de %s de %4d\n",Cal_Greg->get_day_name(&today)
                               ,dia
                               ,Cal_Greg->MES[mes]
                               ,anyo);
 printf("FUENTE: %s\n",source);
 printf("EJECUTABLE: %s\n",exe);
}

void   /**Becomed a friend function of class Calendario on 2020.01.30*/
printf_fecha(Fecha *fPt,Calendario *Cal_Greg)
{
#if 0//LMC 2022.03.11
    printf("%15s %2d de %s de %4d\n",Cal_Greg->get_day_name(fPt)
#else
    printf("%s %2d de %s de %4d\n",Cal_Greg->get_day_name(fPt)
#endif
                                     ,fPt->d
                                     ,Cal_Greg->MES[fPt->m]
                                     ,fPt->a);
}

/**
 * @param hms hour minute or second
 */
std::string left_zeroer(short hms)
{
 char str[8];
 if (hms<10){
   sprintf(str,"0%i",hms);
 }else{
   sprintf(str,"%i",hms);
 }
 return std::string(str);
}


