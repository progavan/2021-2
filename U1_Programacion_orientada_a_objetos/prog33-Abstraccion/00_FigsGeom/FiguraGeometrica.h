/** FiguraGeometrica.h */
#include <iostream>

class FiguraGeometrica {
protected:
 std::string name;
public:
 FiguraGeometrica(std::string nombre)
 :name(nombre){/** empty */}
virtual double area() = 0;  /** pure virtual method */
};/*end class FiguraGeometrica */

