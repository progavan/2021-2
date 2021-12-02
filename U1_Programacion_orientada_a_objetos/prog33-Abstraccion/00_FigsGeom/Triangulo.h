/** Triangulo.h */
#ifndef TRIANGULO
#define TRIANGULO
#include <iostream>
#include "FiguraGeometrica.h"

class Triangulo : public FiguraGeometrica {
 double base;
 double altura;
public:
 Triangulo(double B,double A)
 :FiguraGeometrica("Triangulo"),base(B),altura(A) { /** empty */}
 double area() {
   return base * altura / 2;
 }
};/* end class Triangulo */


#endif