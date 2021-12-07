/** Cuadro.h */
#ifndef CUADRO
#define CUADRO
#include <iostream>
#include "FiguraGeometrica.h"

class Cuadro : public FiguraGeometrica {
 double base;
 double altura;
public:
 Cuadro():FiguraGeometrica("Cuadro"),base(0.0),altura(0.0){/** empty */}
 Cuadro(double B,double A)
 :FiguraGeometrica("Rect\\'angulo"),base(B),altura(A) {/** empty */}
 double area() {
   return base * altura;
 }
};/* end class Cuadro */

#endif
