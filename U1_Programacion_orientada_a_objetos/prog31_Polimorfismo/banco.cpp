// banco.cpp - Definición de la clase CBanco.
// Esta clase mantiene una matriz de punteros a
// objetos de cualquier tipo de cuenta bancaria.
//
#include <iostream>
#include <string>
#include <vector>
#include "banco.h"
using namespace std;

CBanco::CBanco() // constructor
{
  // Reservar espacio para 100 elementos (elementos iniciales cero)
  cuentas.reserve(100);
}

CBanco::~CBanco() // destructor
{
  // Eliminar los objetos CCuenta o de sus derivadas
  for (unsigned int i = 0; i < cuentas.size(); i++)
    delete cuentas[i];
}

// banco.cpp
CBanco::CBanco(const CBanco& x)
{
  *this = x; // invoca al operador de asignación
}

CBanco& CBanco::operator=(const CBanco& x)
{
  // Eliminar las cuentas del objeto CBanco destino (*this)
  if (cuentas.size())
  {
    for (unsigned int i = 0; i < cuentas.size(); i++)
      delete cuentas[i];
    // Eliminar todos los elementos de la matriz cuentas
    cuentas.clear();
  }
  // Copiar el banco origen, x, en el banco destino
  for (unsigned int i = 0; i < x.cuentas.size(); i++)
    cuentas.push_back(x.cuentas[i]->clonar());
  return *this;
}

CCuenta *CBanco::operator[](unsigned int i)
{
  // Devolver la referencia al objeto i de la matriz
  if (i >= 0 && i < cuentas.size())
    return cuentas[i];
  else
  {
    cout << "error: índice fuera de límites\n";
    return 0;
  }
}

void CBanco::anyadir(CCuenta *obj)
{ 
  // Añadir un objeto a la matriz
  cuentas.push_back(obj->clonar());
}

bool CBanco::eliminar(string cuenta)
{
  // Buscar la cuenta y eliminar el objeto
  for (unsigned int i = 0; i < cuentas.size(); i++)
    if (cuenta == cuentas[i]->obtenerCuenta())
    {
      delete cuentas[i];
      cuentas.erase(cuentas.begin()+i);
      return true;
    }
  return false;
}

int CBanco::buscar(string str, int pos)
{
  // Buscar un objeto y devolver su posición
  string nom, cuen;
  if (str.empty()) return -1;
  if (pos < 0) pos = 0;
  for (unsigned int i = pos; i < cuentas.size(); i++)
  {
    // Buscar por el nombre del titular de la cuenta
    nom = cuentas[i]->obtenerNombre();
    if (nom.empty()) continue;
    // ¿str está contenida en nom?
    if (nom.find(str) != string::npos)
      return i;
    // Buscar por la cuenta
    cuen = cuentas[i]->obtenerCuenta();
    if (cuen.empty()) continue;
    // ¿str es la cuenta?
    if (str == cuen)
      return i;
  }
  return -1;
}

size_t CBanco::longitud() { return cuentas.size(); }

