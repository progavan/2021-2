#include <iostream>
#include "../include/AritmeticaDHoraDelDia.h"
/** Imprime indicaciones para obtener un fragmento de video. */
void Indicaciones(unsigned int n,
                  AritDHoraDia t_f,
                  AritDHoraDia t_1,
                  AritDHoraDia t_2);
int main(){
 AritDHoraDia T_final(0,39,57);

 AritDHoraDia T_A(0,0,0);
 AritDHoraDia T_B(0,1,25);
 Indicaciones(1,T_final,T_A,T_B);std::cout << "\n";

 AritDHoraDia T_1(0,14,40);
 AritDHoraDia T_2(0,23,55);
 Indicaciones(2,T_final,T_1,T_2);std::cout << "\n";

 AritDHoraDia T_3(0,24,01);
 AritDHoraDia T_4(0,25,44);
 Indicaciones(3,T_final,T_3,T_4);std::cout << "\n";

 AritDHoraDia T_5(0,25,44);
 AritDHoraDia T_6(0,29,03);
 Indicaciones(4,T_final,T_5,T_6);std::cout << "\n";

 AritDHoraDia T_7(0,30,00);
 AritDHoraDia T_8(0,31,19);
 Indicaciones(5,T_final,T_7,T_8);std::cout << "\n";

 AritDHoraDia T_9(0,31,19);
 AritDHoraDia T_10(0,39,57);
 Indicaciones(6,T_final,T_9,T_10);std::cout << "\n";
 return 0;
}/*end main()*/

void Indicaciones(unsigned int n,
                  AritDHoraDia t_f,
                  AritDHoraDia t_1,
                  AritDHoraDia t_2)
{
 AritDHoraDia T_A,T_B;
 T_A = t_f - t_1;
 T_B = t_2 - t_1;
 std::cout << "FRAGMENT " << n
           << ":\n Load media\n Reverse\n Cut at "
           << T_A << "\n Reverse\n"
           << " Cut at " << T_B
           << "\n Export "
           << t_1 << " - " << t_2 << "\n";
}
