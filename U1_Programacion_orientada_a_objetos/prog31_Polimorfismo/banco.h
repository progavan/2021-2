// banco.h - clase CBanco
#if !defined( _BANCO_H_ )
#define _BANCO_H_
#include "cuenta.h"

class CBanco
{
  // Atributos
  private:
    std::vector<CCuenta *> cuentas; // matriz de objetos

  // Atributos
  public:
    CBanco();
    ~CBanco();
    CBanco(const CBanco&);            // constructor copia
    CBanco& operator=(const CBanco&); // operador de asignación
    CCuenta *operator[](unsigned int i);
    void anyadir(CCuenta *obj);
    bool eliminar(std::string cuenta);
    int buscar(std::string str, int pos);
    size_t longitud();
};

#endif // _BANCO_H_ 
