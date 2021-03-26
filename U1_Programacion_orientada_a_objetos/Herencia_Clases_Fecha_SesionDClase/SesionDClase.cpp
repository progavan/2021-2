#include "SesionDClase.h"
/**
 * @param horaI: Hora Inicial
 * @param minI: Minuto Inicial
 * @param horaF: HoraFinal
 * @param minF: Minuto Final
 */
SesionDClase::SesionDClase(int dia,int mes,int annio,
                     int horaI,int minI,int horaF,int minF)
:Fecha(dia,mes,annio),HI(horaI),MI(minI),HF(horaF),MF(minF)
{
    //HI=horaI;MI=minI;HF=horaF;MF=minF;
    /**Estos atributos se inicializan en el constructor
       de la clase base.
    d=dia;
    m=mes;
    a=annio;
    */
}

SesionDClase::~SesionDClase()
{
    //dtor
}

ostream& operator<<(ostream& out,SesionDClase& rhs){
 Fecha Tmp(rhs.get_d(),rhs.get_m(),rhs.get_a());
 //Figueroa Soriano Braulio
 //Emilio Vazquez
 //Rene Samuel Lopez Vicente
 //Ricardo Hernandez Gonzalez
 out <<Tmp << " ["
        << rhs.HI<<":";
 if (rhs.MI<10){
    out <<"0";
 }
 out<<rhs.MI<<" - "
        << rhs.HF<<":";
 if (rhs.MF<10){
    out <<"0";
 }
out<<rhs.MF<<" ]";
 /*out << Tmp << " ["
     << HI <<":"<<MI << " - "
     << HF <<":"<<MF << "]";*/
 return out;
}

//SesionDClase::SesionDClase
//            (Fecha f,int horaI,int minI,int horaF,int minF)
////WRITE YOUR CODE HERE
//{
//// OR HERE.
//}
//Sergio Valente Rodríguez Morquecho, 2021.03.26 11:41
SesionDClase::SesionDClase(Fecha f, int horaI, int minI, int horaF, int minF)
:Fecha(f),HI(horaI),MI(minI),HF(horaF),MF(minF)
{
}
