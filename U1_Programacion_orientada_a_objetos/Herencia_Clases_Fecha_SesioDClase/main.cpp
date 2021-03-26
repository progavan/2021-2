#include <iostream>
using namespace std;
#include "Fecha.h"
#include "SesionDClase.h"//Sergio Valente Rodríguez Morquecho

int main()
{
    cout << "EJEMPLO CLASE Fecha" << endl;
    Fecha FT;
    //FT.d = 12;
    //cout << "DIA: "<<FT.d<<endl;
    FT.set_d(12);
    FT.set_m(3);
    FT.set_a(2021);
    //Fecha& FR=FT;
    cout<<"\n";
    cout<<FT<<"\n";
    Fecha F1(17,3,2021);
    cout<<F1<<endl;
    cout<<"F1.F = "<<F1.get_F()<<"\n";
    if (FT<F1){
     cout<<FT<<"\n"<<F1<<"\n";
    }else{
     cout<<F1<<"\n"<<FT<<"\n";
    }
    //Instanciar un objeto de la clase SesionDClase
    //Imprimir utilizando el operador << el objeto de
    //la clase SeSionDClase que se acaba de instanciar.
    //Sergio Valente Rodríguez Morquecho
    SesionDClase SDC1 (24,3,2021,11,30,13,0);
    cout << SDC1 << endl;
    SesionDClase SDC2 (26,3,2021,11,30,13,0);
    cout << SDC2 << endl;
    Fecha F2(31,3,2021);
    SesionDClase SDC3(F2,11,30,13,0);
    //SesionDClase SDC4(F2+14,11,30,13,0);
    //cout << SDC3 << endl << SDC4 << endl;
    cout<<SDC3<<endl;
    return 0;
}
