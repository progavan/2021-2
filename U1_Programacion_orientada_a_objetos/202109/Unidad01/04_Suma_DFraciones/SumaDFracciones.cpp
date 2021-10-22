#include <cmath>
#include <class/Fraccion.h>
#include <class/SumaDFracciones.h>

SumaDFracciones::SumaDFracciones(Fraccion *op1,
                                 Fraccion *op2,
                                 Fraccion *rslt)
:F_op1(op1),F_op2(op2),F_rslt(rslt)
{/**Deliberadamente vac\'io*/}

/**Stub*/
std::ostream& operator<<(std::ostream& out,
                                SumaDFracciones SdFrhs){
 out << "Suma de Fracciones";
 return out;
}
