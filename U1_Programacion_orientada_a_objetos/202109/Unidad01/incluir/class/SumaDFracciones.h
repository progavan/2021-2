#ifndef SUMADFRACCIONES_H_INCLUDED
#define SUMADFRACCIONES_H_INCLUDED
#include <iostream>
class Fraccion;
class SumaDFracciones {
 Fraccion *F_op1;    /** Apuntador a la Fraccion operando1 */
 Fraccion *F_op2;    /** Apuntador a la Fraccion operando2 */
 Fraccion *F_rslt;   /** Apuntador a la Fraccion resultado */
public:
 SumaDFracciones(Fraccion *op1,Fraccion *op2,Fraccion *rslt);
 SumaDFracciones(Fraccion *op1,Fraccion *op2);
 std::string to_string();/** Codifica una cadena en \LaTeX
                             para mostrar en un archivo gif
                             la suma de fracciones. */
friend std::ostream& operator<<(std::ostream&,
                                SumaDFracciones);
};
#endif // SUMADFRACCIONES_H_INCLUDED
