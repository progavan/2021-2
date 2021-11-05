#ifndef EQUIVDFRACIONES_H_INCLUDED
#define EQUIVDFRACIONES_H_INCLUDED
#include <iostream>
#include <vector>
class Fraccion;
class EquivDFracciones {
 Fraccion *F_Pt;
public:
 EquivDFracciones(Fraccion *p);
 std::string to_string();/** Codifica una cadena en \LaTeX */
};/*end class EquivDFracciones */

// Moved to file common.h
//void display_gui(std::vector<std::string>& gifFile,
//                 int x0,
//                 int y0);
//int create_gif(std::string gifFileName,
//               std::string laTeXexp);
#endif // EQUIVDFRACIONES_H_INCLUDED
