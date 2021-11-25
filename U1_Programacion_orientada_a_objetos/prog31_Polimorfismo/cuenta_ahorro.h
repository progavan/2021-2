// cuenta_ahorro.h - Declaración de la clase CCuentaAhorro
#if !defined( _CUENTA_AHORRO_H_ )
#define _CUENTA_AHORRO_H_
#include "cuenta.h"

class CCuentaAhorro : public CCuenta
{
  // Atributos
  private:
    double cuotaMantenimiento;
  
  // Métodos
  public:
    CCuentaAhorro(std::string nom = "sin nombre", std::string cue = "0000",
         double sal = 0.0, double tipo = 0.0, double mant = 0.0);
    CCuentaAhorro(const CCuentaAhorro&);
    CCuentaAhorro& operator=(const CCuentaAhorro&);
    bool asignarCuotaManten(double);
    double obtenerCuotaManten() const;
    void comisiones();
    double intereses();
    CCuentaAhorro *clonar();
};

#endif // _CUENTA_AHORRO_H_ 

