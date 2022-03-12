/** DiasTranscurridos.cpp */
#include <iostream>
#include <ctime>
#include <cstdio>
#include "Unidad01_util.h"
#include "Fecha.h"
#include "gettingdate.h"
#include "Calendario.h"

#ifdef CONFIG_DIAS_TRANSCURRIDOS
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

 Fecha H(dia,mes,anyo);   /** Usamos el constructor que recibe 3 int */
 Fecha Ene01(1,1,anyo);
#if 0//LMC 2022.03.11
 print_ident_data(__FILE__,argv[0]);
#else
 print_ident_data_cpp(__FILE__,argv[0]);
#endif // 0
 if (hora<10){
   sprintf(str,"0%i",hora);
 }else{
   sprintf(str,"%i",hora);
 }
 Hora = std::string(str);
 if (min<10){
   sprintf(str,"0%i",min);
 }else{
   sprintf(str,"%i",min);
 }
 Min = std::string(str);
 if (sec<10){
   sprintf(str,"0%i",sec);
 }else{
   sprintf(str,"%i",sec);
 }
 Sec = std::string(str);

 Calendario *Calend = new Calendario(2022);
 std::cout<<"                             ";
 printf_fecha(&H,Calend);
 std::cout
#if 0
          <<"                                     "
          <<"Jueves "<<H.d<<" de marzo de "<<H.a<<"\n"
#else
          <<"\n"
#endif
          <<Hora<<":"<<Min<<":"<<Sec<<"\n"
          <<"Han transcurrido "<<(H-Ene01)+1<<" d\\'ias de "
          <<anyo<<".\n"
          <<"Faltan por transcurrir "<<365-((H-Ene01)+1)
          <<" d\\'ias de "<<anyo<<".\n";

 return 0;
}/*main()*/
#endif

