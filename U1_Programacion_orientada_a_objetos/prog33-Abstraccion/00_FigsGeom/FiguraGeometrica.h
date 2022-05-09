/** FiguraGeometrica.h */
#ifndef FIGURA_GEOMETRICA
#define FIGURA_GEOMETRICA
#include <iostream>

/**Esta es una clase abstracta, debido a que
contiene un m\'etodo virtual puro. */
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
