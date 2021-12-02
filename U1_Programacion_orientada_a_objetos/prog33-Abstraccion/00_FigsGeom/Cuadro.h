/** Cuadro.h */
#ifndef CUADRO
#define CUADRO
#include <iostream>
#include "FiguraGeometrica.h"

class Cuadro : public FiguraGeometrica {
 double base;
 double altura;
public:
 Cuadro(double B,double A)
 :FiguraGeometrica("Rect\\'angulo"),base(B),altura(A) {/** empty */}
 double area() {
   return base * altura;
 }
};/* end class Cuadro */

#endif
