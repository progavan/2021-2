/**  Circulo.h */
#ifndef CIRCULO
#define CIRCULO
#include <iostream>
#include "FiguraGeometrica.h"

class Circulo : public FiguraGeometrica {
 double radio;
public:
 Circulo():FiguraGeometrica("C\\'irculo"),radio(0.0){/** empty */}
 Circulo(double R)
 :FiguraGeometrica("C\\'irculo"),radio(R) {/** empty */}
 double area(){
  return 3.1416 * radio * radio;
 }
};/*end class Circulo */

#endif
