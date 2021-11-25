// cuenta_corriente+.h - Clase CCuentaCorrienteConIn
#if !defined( _CUENTA_CORRIENTECOIN_H_ )
#define _CUENTA_CORRIENTECOIN_H_
#include "cuenta_corriente.h"

class CCuentaCorrienteConIn : public CCuentaCorriente
{
  // Métodos
  public:
    CCuentaCorrienteConIn(std::string nom = "sin nombre",
        std::string cue = "0000", double sal = 0.0, double tipo = 0.0,
        double imptrans = 0.0, int transex = 0);
    double intereses();
    CCuentaCorrienteConIn *clonar();
};

#endif // _CUENTA_CORRIENTECOIN_H_ 
