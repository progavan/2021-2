/** FiguraGeometrica.h */
#ifndef FIGURA_GEOMETRICA
#define FIGURA_GEOMETRICA
#include <iostream>

class FiguraGeometrica {
//protected:
public:
 std::string name;
public:
 FiguraGeometrica(std::string nombre)
 :name(nombre){/** empty */}
virtual double area() = 0;  /** pure virtual method */
};/*end class FiguraGeometrica */

#endif
