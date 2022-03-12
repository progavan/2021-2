#ifndef FECHA_H
#define FECHA_H
//#if 0 //LMC 2022.03.04
#include "Calendario.h"
//#else
//class Calendario;
//class Dia;
//#endif
extern int anio;
extern short day_in_year(short,short,short);
typedef
struct Fecha{
  int d;/*dia*/
  int m;/**mes, 0 enero, 1 febrero, 2 marzo, etc.
         * Starting from october 29, 2019:
         * 1 for january, 2 for february, 3 for march etcetera */
  int a;/*a\~no*/
  int F;/**F=a\times 10000+m\times 100+d; can be initialized at
         * constructor Fecha(int x,int y,int z)*/
  short Day_in_year;/**day number within the specified year*/
  Fecha():d(0),m(0),a(1){ }/**I changed a(anio) to a(1),2020.01.30*/
  Fecha(int a,int b):d(a),m(b),a(1){ }/** idem */
  /*2019.10.20,2020.01.28*/
  Fecha(int x,int y,int z):
  d(x),m(y),a(z),F(z*10000+y*100+x){ }
  /*sobrescritura (sobrecarga/overloading) del operador ==*/
  /*overloading of the operator ==*/ /*2020.01.27*/
  bool operator==(Fecha& f){
    return ((d==f.d)&&(m==f.m));
  }
  bool operator>(Fecha& f){return (F>f.F);}
  bool operator>=(Fecha& f){return F>=f.F;}
  bool operator<=(Fecha& f){return F<=f.F;}
  short operator-(Fecha& f);
} Fecha;
void printf_fecha(Fecha *,Calendario *);
#ifdef CONFIG_USING_CALENDARIO_FOR_PLANNING
void show_vector_ddconf(std::vector<Dia*>);
void ordenar_ddc(std::vector<Dia*>&);  /*solved at file bubbles.cpp*/
void cat_vddc(std::vector<Dia*>&,
              std::vector<Dia*>&,
              std::vector<Dia*>&);
#endif // CONFIG_USING_CALENDARIO_FOR_PLANNING
#endif /*FECHA_H*/
