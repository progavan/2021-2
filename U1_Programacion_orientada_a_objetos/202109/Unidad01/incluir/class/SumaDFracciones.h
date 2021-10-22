#ifndef SUMADFRACCIONES_H_INCLUDED
#define SUMADFRACCIONES_H_INCLUDED
class Fraccion;
class SumaDFracciones {
 Fraccion *F_op1;
 Fraccion *F_op2;
 Fraccion *F_rslt;
public:
 SumaDFracciones(Fraccion *op1,Fraccion *op2,Fraccion *rslt);
 std::string to_string();/** Codifica una cadena en \LaTeX
                             para mostrar un archivo gif
                             la suma de fracciones. */
friend std::ostream& operator<<(std::ostream&,
                                SumaDFracciones);
};
#endif // SUMADFRACCIONES_H_INCLUDED
