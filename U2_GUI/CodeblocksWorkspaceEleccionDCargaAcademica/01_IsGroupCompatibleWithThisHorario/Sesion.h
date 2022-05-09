#ifndef SESION_H_INCLUDED
#define SESION_H_INCLUDED
#include <iostream>
class Sesion {
 char D;      /** D\'ia 'L' LUNES,'M' MARTES,'X' MIERCOLES, ...*/
 short HdI;   /** Hora de Inicio (supongo sesiones de duraci\'on:
         830-700=130,1000-830=170,1130-1000=130,1300-1130=170,
         1430-1300=130,1600-1430=170,1730-1600=130,1900-1730=170)*/
 short HdF;   /** Hora de Finalizaci\'on, campo calculado */
public:
 Sesion(char d,short hdi):D(d),HdI(hdi),
 HdF(((hdi%100)==0)?hdi+130:hdi+170)
 {/**deliberadamente vac\'io*/}
friend std::ostream& operator<<(std::ostream& out,Sesion rhs)
{
 std::string dn;
 switch(rhs.D){
   case 'L':{dn="Lunes";break;}
   case 'M':{dn="Martes";break;}
   case 'X':{dn="Mi\\'ercoles";break;}
   case 'J':{dn="Jueves";break;}
   case 'V':{dn="Viernes";break;}
   default:{dn="No D\\'ia";break;}
 }
 out<<dn<<" "<<rhs.HdI<<"-"<<rhs.HdF;
 return out;
 }
 bool operator==(Sesion rhs)
 {
  return ((D==rhs.D)&&(HdI==rhs.HdI));
  //Mi\'ercoles 13 de abril de 2022
  //De hecho se debe poder considerar que dos sesiones
  //tiene `traslape' si sus intervalos
  //de tiempo tienen intersecci\'on no vacia. Hay que
  //agregar una operaci\'on para las sesiones que
  //permita saber si dos sesiones se traslapan.
  //Por ejemplo se puede decir que dos sesiones se
  //traslapan si limite inferior de cualquiera de ellas
  //pertenece al intervalo de la otra sesi\'on, o bien
  //si el limite superior de cualquiera de ellas
  //pertenece al intervalo de la otra sesi\'on
 }
 short get_Y(){
  switch(D){
  case 'L':{return 1;}
  case 'M':{return 2;}
  case 'X':{return 3;}
  case 'J':{return 4;}
  case 'V':{return 5;}
  default:{return 0;}
  }
 }
 short get_X(){
  switch(HdI){
  case 700:{return 1;}
  case 830:{return 2;}
  case 1000:{return 3;}
  case 1130:{return 4;}
  case 1300:{return 5;}
  case 1430:{return 6;}
  case 1600:{return 7;}
  case 1730:{return 8;}
  case 1900:{return 9;}
  default:{return 0;}
  }
 }
};/*end class Sesion*/


#endif // SESION_H_INCLUDED
