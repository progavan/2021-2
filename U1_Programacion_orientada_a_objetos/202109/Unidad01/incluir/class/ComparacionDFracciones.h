#ifndef COMPARACIONDFRACCIONES_H_INCLUDED
#define COMPARACIONDFRACCIONES_H_INCLUDED
class Fraccion;
class ComparacionDFracciones {
 Fraccion *F_op1;    /** Apuntador a la Fraccion operando1 */
 Fraccion *F_op2;    /** Apuntador a la Fraccion operando2 */
 char rel;           /** '>','=','<'*/
public:
 ComparacionDFracciones(Fraccion *op1,Fraccion *op2);
 std::string to_string();/** Codifica una cadena en \LaTeX
                             para mostrar en un archivo gif
                             la comparaci\'on de Fracciones.*/
 char get_rel();     /** getter para rel */
};
#endif // COMPARACIONDFRACCIONES_H_INCLUDED
