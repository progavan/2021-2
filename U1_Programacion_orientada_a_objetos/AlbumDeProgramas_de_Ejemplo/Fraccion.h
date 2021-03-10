#ifndef FRACCION_H_INCLUDED
#define FRACCION_H_INCLUDED
/**Usaremos para este primer ejemplo de una clase,
la palabra reservada struct.
Con la palabra reservada struct se puede declarar
una clase en C++. En C++, las estructuras también
son clases, con la restricción de que son clases
que solamente tienen una sección pública, es decir,
son clases sin secciones privadas ni secciones
protegidas.
*/
#include <fstream>

struct Fraccion{/*Clase Fraccion*/
 int numerador;
 int denominador;
 Fraccion();
 Fraccion(int num,int den);
 void simplificar();
 unsigned int mcd();
friend std::ostream&
       operator<<(std::ostream& out,Fraccion& rhs);
};/*end struct Fraccion*/


#endif // FRACCION_H_INCLUDED
