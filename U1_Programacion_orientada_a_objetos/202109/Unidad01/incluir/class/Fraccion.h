#ifndef FRACCION_H_INCLUDED
#define FRACCION_H_INCLUDED
#include <iostream>
/**
 1: La clase Fraccion tiene los atributos n, d, N y D en
    una secci\'on p\'ublica. La sobrecarga del operador
    << se puede resolver como una funci\'on aislada. Es
    necesario colocar una declaraci\'on anticipada de la
    clase Fraccion antes del prototipo de la funci\'on
    operator<<()
 0: La clase Fraccion tendr\'a los atributos n, d, N y D
    con visibilidad por defecto (privada). La sobrecarga
    del operador << deber\'a especificarse como funci\'on
    amiga (friend) de la clase Fraccion.
*/
  #if 0
class Fraccion; /** Declaraci\'on anticipada de clase */
std::ostream& operator<<(std::ostream&,Fraccion rhs);
class Fraccion {
public:
  #else
class Fraccion {
friend std::ostream& operator<<(std::ostream&,Fraccion rhs);
friend class EquivDFracciones;
  #endif
 int n;                   /** numerador*/
 int d;                   /** denominador*/
 unsigned int N;          /** N=abs(n) */
 unsigned int D;          /** D=abs(d) */
public:
 Fraccion(int num,int den);
/**
 1: Se conserva el constructor por defecto para no romper
    el objetivo 01_constructores.
 0: Se rompe el objetivo 01_constructores.
*/
 #if 1
 Fraccion();
 #endif
 /** Operacion de la clase Fraccion */
 Fraccion operator+(Fraccion rhs);

 void simplificar();
 unsigned int MCD(int NUM,int DEN);
#if 1 //2021.10.05
 std::string to_string();/** Codifica una cadena en \LaTeX */
#endif
#if 1 //2021.10.14
 char signo();/** '+' Si la Fracci\'on es > 0.
                  '-' Si la Fracci\'on es < 0.
               */
#endif
};/* end class Fraccion */

#endif // FRACCION_H_INCLUDED
