#include <cmath>
#include <Fraccion.h>

Fraccion::Fraccion()
{/*constructor por defecto*/
   numerador=denominador=1;
}

Fraccion::Fraccion(int num,int den)
{/*constructor*/
   numerador=num;
   denominador=den;
}

void Fraccion::simplificar()
{
  int MCD;
  MCD=(int)mcd();
  numerador=numerador/MCD;
  denominador=denominador/MCD;
}

unsigned int Fraccion::mcd()
{
  unsigned int N,D,aux;
  N=abs(numerador);
  D=abs(denominador);
  if(N<D){
   aux=N;
   N=D;
   D=aux;
  }
  while((aux=N%D)!=0){/*Algoritmo de Euclides*/
   N=D;
   D=aux;
  }
  return D;
}

std::ostream& operator<<(std::ostream& out,Fraccion& rhs){
 out<<rhs.numerador<<"/"<<rhs.denominador;
 return out;
}
