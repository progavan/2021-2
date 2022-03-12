/** DiasTranscurridos_1.cpp */
#include <iostream>
#include <ctime>
#include <cstdio>
#include "Unidad01_util.h"
#include "Fecha.h"
#include "gettingdate.h"
#include "Calendario.h"

#ifdef CONFIG_DIAS_TRANSCURRIDOS_1
int main(int argc,char *argv[])
{
 int dia,mes,anyo;
 int hora,min,sec;
 char str[8];
 std::string Hora,Min,Sec;

 time_t now = time(0);
 tm *ltm = localtime(&now);
 anyo = get_year(ltm);
 mes = get_month(ltm);
 dia = get_day(ltm);
 hora = get_hour(ltm);
 min = get_min(ltm);
 sec = get_sec(ltm);
 Hora = left_zeroer(hora);
 Min = left_zeroer(min);
 Sec = left_zeroer(sec);

 Fecha H(dia,mes,anyo);
 Fecha Ene01(1,1,anyo);
 Calendario *Calend = new Calendario(2022);

 print_ident_data(__FILE__,argv[0]);
 printf_fecha(&H,Calend);
 std::cout<<Hora<<":"<<Min<<":"<<Sec<<"\n"
          <<"Han transcurrido "<<(H-Ene01)+1<<" d\\'ias de "
          <<anyo<<".\n"
          <<"Faltan por transcurrir "<<365-((H-Ene01)+1)
          <<" d\\'ias de "<<anyo<<".\n";

 return 0;
}/*end main()*/
#endif

