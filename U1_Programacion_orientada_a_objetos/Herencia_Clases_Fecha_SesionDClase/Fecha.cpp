#include "Fecha.h"
/**
 NumDelMes = 1 (enero),
 NumDelMes = 2 (febrero),
 ...
 NumDElMes = 12(diciembre)
*/
unsigned int DiasDelMes(int NumDelMes,int annyo){
 return 0;
}

Fecha::Fecha()
{
    //ctor
}

Fecha::Fecha(int dia,int mes,int annio)//:
//d(dia),m(mes),a(annio) /*inicializadores*/
{ d=dia;m=mes;a=annio;
  set_F();  /*utilizando los valores de los atributos
              d, m y a, calcula y asigna el valor entero
              correspondiente al atributo F */
}

void Fecha::set_d(int dia)
{
 d=dia;
}
int Fecha::get_d()
{
 return d;
}
void Fecha::set_m(int mes)
{
 m=mes;
}
int Fecha::get_m()
{
 return m;
}
void Fecha::set_a(int annio)
{
 a=annio;
}
int Fecha::get_a()
{
 return a;
}

ostream& operator<<(ostream& out,Fecha& rhs)
{rhs.set_F();
 out<<rhs.d<<"/";
 if(rhs.m<10) out<<"0";
 out<<rhs.m<<"/"<<rhs.a<<" ("
    <<rhs.F<<")";
 return out;
}

/** m\'etodo privado set_F()*/
/**Emilio Vazquez
 cabecera del m\'etodo set_F()
*/
void Fecha::set_F(){
 //René Samuel López Vicente
 //int F,a1, m1 ;
 int a1, m1 ;
        a1=a*10000;
        m1=m*100;
        F=a1+m1+d;
}

int Fecha::get_F(){
 return F;
}

/**Ricardo Hernández Gonzalez
 cabecera del método operator< para la clase Fecha
*/
bool Fecha::operator<(Fecha rhs)
{//Sergio Valente Rodríguez
//bool B = 'false'; if (F < rhs.F) {B = ''true'}; return B;
//bool B = false; if (F < rhs.F) {B = true}; return B;
bool B = false; if (F < rhs.F) {B = true;} return B;
}
/**Stub*/
Fecha Fecha::operator+(unsigned int k){
 Fecha EF(0,0,0); /**Coincide con la Fecha del objeto impl\'icito*/
 return EF;
}

