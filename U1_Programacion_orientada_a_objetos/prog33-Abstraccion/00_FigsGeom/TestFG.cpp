/** TestFG.cpp */
#include <iostream>
#include "Cuadro.h"
#include "Circulo.h"
#include "Triangulo.h"
#include "../prog33-Abstraccion_util.h"
#define SIZE_ARR(a)    ((sizeof(a))/(sizeof(a[0])))

int main(int argc,char *argv[])
{
 FiguraGeometrica *arr[3];
 //std::cout <<"sizeof(arr):"<<sizeof(arr)<<std::endl;
 arr[0] = new Cuadro(20,10);
 arr[1] = new Triangulo(30,15);
 arr[2] = new Circulo(10);
 print_ident_data(__FILE__,argv[0]);printf("\n");
 for(unsigned int i = 0;i < SIZE_ARR(arr);i++){
   std::cout << i << " "
             << arr[i]->name << " con \\'area "
             << arr[i]->area() // Comportamiento polim\'orfico
             << std::endl;     // del m\'etodo area()
 }
#if 0 //DEBUG
 for(unsigned int i = 0;i<SIZE_ARR(arr);i++){
   delete[] arr[i];
 }
#endif
 return 0;
}/*end main()*/



