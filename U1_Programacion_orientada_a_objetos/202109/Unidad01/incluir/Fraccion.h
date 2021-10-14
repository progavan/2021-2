#ifndef FRACCION_H_INCLUDED
#define FRACCION_H_INCLUDED
#include <iostream>
#include <cmath>
/**Ejemplo de una clase sin secciones privadas*/
/**Esta clase se puede usar para modelar n\'umeros
   racionales */
/**Stub*/


typedef struct Fraccion {
 int n;                   /** numerador*/
 int d;                   /** denominador*/
 unsigned int N;          /** N=abs(n) */
 unsigned int D;          /** D=abs(d) */
 Fraccion(int num,int den);
 #if 1
 Fraccion();
 #endif
 Fraccion operator+(Fraccion rhs); /** Operacion de la clase Fraccion */

 void simplificar();
 unsigned int MCD(int NUM,int DEN);
} Fraccion;
std::ostream& operator<<(std::ostream&,Fraccion rhs);
#endif // FRACCION_H_INCLUDED
