/** Triangulo.h */
#ifndef TRIANGULO
#define TRIANGULO
#include <iostream>
#include "FiguraGeometrica.h"

class Triangulo : public FiguraGeometrica {
 double base;
 double altura;
public:
 Triangulo()
 :FiguraGeometrica("Tri\\'angulo"),base(0.0),altura(0.0){/**empty*/}
 Triangulo(double B,double A)
 :FiguraGeometrica("Tri\\'angulo"),base(B),altura(A) { /** empty */}
 double area() {
   return base * altura / 2;
 }
};/* end class Triangulo */


#endif
