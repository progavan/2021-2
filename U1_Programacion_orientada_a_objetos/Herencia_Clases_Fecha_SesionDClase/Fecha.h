#ifndef FECHA_H
#define FECHA_H
#include <iostream>  /*ofstream*/
using namespace std;
class Fecha  /**Clase base de la clase SesionDClase*/
{
protected:
    int d;    /*dia*/
    int m;    /*mes*/
    int a;    /*a\~no*/
    int F;    /**Fecha como n\'umero entero
                 Es decir, por ejemplo, a la fecha de hoy
                 12 de marzo de 2021 le corresponder\'a
                 el valor F=20210312. El cual puede obtenerse
                 con la siguiente f\'ormula:
                 10000\times a + 100\times m + d */

public:
    Fecha();
    Fecha(int dia,int mes,int annio);
                          /*M\'etodos de acceso*/
    void set_d(int dia);  /*setter*/
    int get_d();          /*getter*/
    void set_m(int mes);
    int get_m();
    void set_a(int annio);
    int get_a();
    int get_F();
friend ostream& operator<<(ostream& out,Fecha& rhs);
    bool operator<(Fecha rhs);
    /**Devuelve la fecha correspondiente a la Fecha objeto
       implícito mas k días. Por ejemplo, para la Fecha
       F1=17/03/2021 y k=10, el resultado de la operación
       F1 + 10 debe ser la Fecha 27/03/2021; y para la
       operación F1 + 20, el resultado debe ser 6/04/2021 */
    Fecha operator+(unsigned int k);

protected:

private:
    /**utilizando los valores de los atributos
      d, m y a, calcula y asigna el valor entero
      correspondiente al atributo F, por ejemplo,
      para la fecha 1/01/2021 el valor del atributo
      F debe ser 20210101. Otro ejemplo, para la
      fecha 17/03/2021, el valor del atributo F
      debe ser 20210317.Para este ejemplo (20210317),
      designemos U=17, C=3, y DM=2021, entonces,
      20210317 = 10000*DM + 100*C + 17
                 20210000 + 300 + 17
     */
    void set_F();
};

#endif // FECHA_H
