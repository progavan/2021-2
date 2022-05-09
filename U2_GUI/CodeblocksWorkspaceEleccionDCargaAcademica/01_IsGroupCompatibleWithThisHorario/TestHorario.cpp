#include <iostream>
using namespace std;
//#include "Unidad01_util.h"
#include "Sesion.h"
#include "Grupo.h"
#include "Horario.h"
std::string Horario::HFaG[ROWS][COLS] = {
{"           ","LUNES","MARTES","MIERCOLES","JUEVES","VIERNES"},
{"07:00-08:30","     ","      ","         ","      ","       "},
{"08:30-10:00","     ","      ","         ","      ","       "},
{"10:00-11:30","     ","      ","         ","      ","       "},
{"11:30-13:00","     ","      ","         ","      ","       "},
{"13:00-14:30","     ","      ","         ","      ","       "},
{"14:30-16:00","     ","      ","         ","      ","       "},
{"16:00-17:30","     ","      ","         ","      ","       "},
{"17:30-19:00","     ","      ","         ","      ","       "},
{"19:00-20:30","     ","      ","         ","      ","       "},
};

void show_tabla(std::string hfag[ROWS][COLS]);
int main(int argc,char *argv[])
{
 Horario H;
 /**'L' Lunes,'M' Martes,'X' Mi\'ercoles,'J' Jueves,'V' Viernes*/
 Sesion S00_0('L',1600),S00_1('X',1600),S00_2('J',1430);
 Sesion S00_3('J',1600),S00_4('V',1600);
 Sesion S00_5('M',1430),S00_6('X',1430),S00_7('V',1430);
 Sesion S0('L',1130),S1('M',1300),S2('V',1130);
 Sesion S3('M',1430),S4('V',1430);
 Sesion S5('L',1130),S6('X',1130),S7('V',1130);
 Sesion S8('M',1300),S9('X',1130),S10('V',1130);
 Sesion S11('L',1300),S12('M',1300),S13('X',1300);

#ifdef CONFIG_HORARIO_03
 Grupo G0("1TV1","PROGEST",&S11,&S12,&S13);
 Grupo G1("2MV9","PROGA",&S3,&S4);
 Grupo G2("3MM26","SOTR",&S5,&S6,&S7);
#endif // HORARIO_03
#ifdef CONFIG_HORARIO_02
 Grupo G0("1MM2","INTROPROG",&S8,&S9,&S10);
 Grupo G1("2MV9","PROGA",&S3,&S4);
 Grupo G2("3MM26","SOTR",&S5,&S6,&S7);
#endif // HORARIO_02
#ifdef CONFIG_HORARIO_01
 Grupo G0("1MM1","INTROPROG",&S0,&S1,&S2);
 Grupo G1("2MV9","PROGA",&S3,&S4);
 Grupo G2("3MM26","SOTR",&S5,&S6,&S7);
#endif // HORARIO_01
#ifdef CONFIG_HORARIO_00
 Grupo G0("1MV3","INTROPROG",&S00_0,&S00_1,&S00_2);
 Grupo G1("2MV4","PROGA",&S00_3,&S00_4);
 Grupo G2("3MM26","SOTR",&S00_5,&S00_6,&S00_7);
#endif // HORARIO_00
// std::cout<<G0<<"\n"<<G1<<"\n"<<G2<<"\n";
 if (H.is_group_comp(G0)) {
   H.add(G0);
 }
 if (H.is_group_comp(G1)) {
   H.add(G1);
 }
 if (H.is_group_comp(G2)) {
   H.add(G2);
 }
// print_ident_data(__FILE__,argv[0]);
 if (3 == H.get_cardinality()){
   std::cout<<H<<"\n";
   H.show();
 }else{
   std::cout<<G0<<"\n"<<G1<<"\n"<<G2<<"\n";
   std::cout<<"LOS GRUPOS \n";
   std::cout<<G0.get_NdG()
            <<", "<<G1.get_NdG()
            <<", "<<G2.get_NdG();
   std::cout<<"\nNO SON COMPATIBLES\n";
 }
 //std::string arr[ROWS][COLS] = Horario::get_HFaG();
 //std::string arr[ROWS][COLS] = Horario::HFaG;
 printf("\n\n");
 //show_tabla(Horario::HFaG);
 return 0;
}/*end main()*/
