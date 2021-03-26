#ifndef SESIONDCLASE_H
#define SESIONDCLASE_H

#include <Fecha.h>
/**SesionDClase es una clase derivada de la clase Fecha*/

class SesionDClase : public Fecha {
    //Fecha fecha;
    public:
        SesionDClase(int dia,int mes,int annio,
                     int horaI,int minI,int horaF,int minF);
        SesionDClase(Fecha,int horaI,int minI,int horaF,int minF);
        ~SesionDClase();
friend ostream& operator<<(ostream& out,SesionDClase& rhs);

    protected:

private:
 int HI;         /**Hora Inicial*/
 int MI;         /**Minuto Inicial*/
 int HF;         /**Hora Final*/
 int MF;         /**Minuto Final*/
};

#endif // SESIONDCLASE_H
