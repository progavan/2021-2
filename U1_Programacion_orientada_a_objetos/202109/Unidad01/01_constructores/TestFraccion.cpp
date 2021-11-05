#include <iostream>
/**                   Jueves 28 de octubre de 2021.
    0: Con 0 se utiliza la definici\'on de la clase
       Fraccion con la palabra reservada class.
    1: Con 1 se utiliza la definici\'on de la clase
       Fraccion con la palabra reservada struct.
    Pero con 1, se rompe el objetivo 02_metodos y
    objetivos posteriores. Por otra parte, con 0 no
    se rompe el objetivo 01_constructores (si en la
    clase Fraccion se incluye el constructor por
    defecto -- Fraccion() --).
 */
#if 0 //LMC 2021.10.28
#include <Fraccion.h>
#else
#include <class/Fraccion.h>
#endif
using namespace std;

int main(){
 Fraccion F1(1,2);   /** 1/2 */
 Fraccion F2(1,4);   /** 1/4 */
 Fraccion F3 = F1 + F2;
 cout<<"SUMA DE FRACCIONES"<<endl;
#if 0 //LMC 2021.10.28, Esto ya no se puede usar porque
      //en class/Fraccion.h los atributos n y d son
      //privados.
 cout<<F1.n<<"/"<<F1.d<<" + "
     <<F2.n<<"/"<<F2.d<<" = "
     <<F3.n<<"/"<<F3.d<<endl;
#else
 cout<<F1<<" + "<<F2<<" = "<<F3<<"\n";
#endif // 0
//#if 0 //LMC 2021.10.28.21.40
 Fraccion F;
 Fraccion arr_F[3];    /** <--Requiere de constructor por */
                       /** defecto. Para resolver el error*/
                       /** agregaremos el constructor por */
                       /** defecto. */

 arr_F[0] = F1;
 arr_F[1] = F2;
 arr_F[2] = arr_F[0] + arr_F[1];
 F = arr_F[2];
#if 0 //LMC 2021.10.28.22.00
 cout<<arr_F[0].n<<"/"<<arr_F[0].d<<" + "
     <<arr_F[1].n<<"/"<<arr_F[1].d<<" = "
 #if 0
     <<arr_F[2].n<<"/"<<arr_F[2].d<<endl;
 #else
     <<F.n<<"/"<<F.d<<endl;
 #endif
#else
 cout<<arr_F[0]<<" + "<<arr_F[1]<<" = "<<F;
#endif // 0
 return 0;
}/*end main()*/

