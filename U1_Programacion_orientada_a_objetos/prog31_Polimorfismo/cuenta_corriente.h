// cuenta_corriente.h - Declaración de la clase CCuentaCorriente
#if !defined( _CUENTA_CORRIENTE_H_ )
#define _CUENTA_CORRIENTE_H_
#include "cuenta.h"

class CCuentaCorriente : public CCuenta
{
  // Atributos
  private:
    int transacciones;
    double importePorTrans;
    int transExentas;
  
  // Métodos
  public:
    CCuentaCorriente(std::string nom = "sin nombre", std::string cue = "0000",
                     double sal = 0.0, double tipo = 0.0,
                     double imptrans = 0.0, int transex = 0);
    void decrementarTransacciones();
    bool asignarImportePorTrans(double);
    double obtenerImportePorTrans() const;
    bool asignarTransExentas(int);
    int obtenerTransExentas() const;
    void ingreso(double);
    void reintegro(double);
    void comisiones();
    double intereses();
    CCuentaCorriente *clonar();
};

#endif // _CUENTA_CORRIENTE_H_ 
