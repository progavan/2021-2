#include <iostream>
#include <Fraccion.h>
using namespace std;

int main(){
 Fraccion F1(1,2);   /** 1/2 */
 Fraccion F2(1,4);   /** 1/4 */
 Fraccion F3 = F1 + F2;
 cout<<"SUMA DE FRACCIONES"<<endl;
 cout<<F1.n<<"/"<<F1.d<<" + "
     <<F2.n<<"/"<<F2.d<<" = "
     <<F3.n<<"/"<<F3.d<<endl;
 Fraccion F;
 Fraccion arr_F[3];    /** <--Requiere de constructor por */
                       /** defecto. Para resolver el  */
                       /** agegaremos el constructor por */
                       /** defecto. */
 arr_F[0] = F1;
 arr_F[1] = F2;
 arr_F[2] = arr_F[0] + arr_F[1];
 F = arr_F[2];
 cout<<arr_F[0].n<<"/"<<arr_F[0].d<<" + "
     <<arr_F[1].n<<"/"<<arr_F[1].d<<" = "
 #if 0
     <<arr_F[2].n<<"/"<<arr_F[2].d<<endl;
 #else
     <<F.n<<"/"<<F.d<<endl;
 #endif

 return 0;
}/*end main()*/

