// main1.cpp Ejemplifica el uso de
// funciones amigas
#include <iostream>
using namespace std;

class Base {
  friend void FnAmigaDeBase();
private:
  void mPrivadoDeBase(){ }
protected:
  void mProtegidoDeBase(){ }
public:
  void mPublicoDeBase(){ }
};

class Derivada : public Base {
  friend void FnAmigaDeDerivada();
private:
  void mPrivadoDeDerivada(){ }
protected:
  void mProtegidoDeDerivada(){ }
public:
  void mPublicoDeDerivada(){ }
};/*end class Derivada*/
/**Funci\'on friend de la clase Base*/
void FnAmigaDeBase(){
  Derivada objD;
  objD.mPrivadoDeBase();  //OK
  objD.mProtegidoDeBase();//OK
  objD.mPublicoDeBase();  //OK
  //objD.mPrivadoDeDerivada();//ERROR
  //objD.mProtegidoDeDerivada();//ERROR
  objD.mPublicoDeDerivada();//OK
}
void FnAmigaDeDerivada(){
  Derivada objD;
  //objD.mPrivadoDeBase();//ERROR
  objD.mProtegidoDeBase();//OK
  objD.mPublicoDeBase();  //OK
  objD.mPrivadoDeDerivada();  //OK
  objD.mProtegidoDeDerivada();//OK
  objD.mPublicoDeDerivada();  //OK
}
#ifdef FUNCIONES_AMIGAS
int main()
{
  Derivada objD;
  //objD.mPrivadoDeBase();  //OK
  //objD.mProtegidoDeBase();//OK
  objD.mPublicoDeBase();  //OK
  return 0;
}
#endif // FUNCIONES_AMIGAS
