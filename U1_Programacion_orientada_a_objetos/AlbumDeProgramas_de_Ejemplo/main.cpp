#include <iostream>
#include <cmath>
using namespace std;
//#include <Fraccion.h>
///**OPCION 1*/
//#include "Fraccion.h"
/**OPCION 2 Somehow add -I<dir containing Fraccion.h> at
 your make file.
 */
#include <Fraccion.h>



int main()
{
 cout << "CLASE Fraccion" << endl;
 Fraccion F(1,2);
 Fraccion F1;
 cout<<F.numerador<<"/"<<F.denominador<<"\n";
 cout<<F1.numerador<<"/"<<F1.denominador<<"\n";
 Fraccion F2(64,132);
 cout<<F2.numerador<<"/"<<F2.denominador<<" = ";
 F2.simplificar();
 cout<<F2.numerador<<"/"<<F2.denominador<<"\n";
 cout<<F2<<"\n";
 return 0;
}/*end main()*/
