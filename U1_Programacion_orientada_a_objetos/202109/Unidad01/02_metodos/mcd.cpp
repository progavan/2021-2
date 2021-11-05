#include <iostream>
#include <cmath>
#if 0
#include <Fraccion.h>
#else
#include <class/Fraccion.h>
#endif
#if 0 /** Con 0, ahora MCD es un m\'etodo. */
unsigned int MCD(int n,int d)
#else
unsigned int Fraccion::MCD(int n,int d)
#endif
{
  unsigned int N,D,aux;
  N=abs(n);
  D=abs(d);
  if(N<D){
   aux=N;
   N=D;
   D=aux;
  }
  while((aux=N%D)!=0){/*Algoritmo de Euclides*/
  //#if 1 //LMC 2021.10.28.17.30
  #if 0 //LMC 2021.10.28.17.50
   std::cout << "EUCLIDES: while((aux=N%D)!=0)\n";
  #endif
   N=D;
   D=aux;
  }
  return D;
}

