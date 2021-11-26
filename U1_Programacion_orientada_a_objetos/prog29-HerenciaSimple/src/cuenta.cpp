// cuenta.cpp - Definici�n de la clase CCuenta
#include <iostream>
#include "cuenta.h"
using namespace std;

//////////////////////////////////////////////////////////////////
// Clase CCuenta: clase que agrupa los datos comunes a
// cualquier tipo de cuenta bancaria.
//
CCuenta::CCuenta(string nom, string cue, double sal, double tipo) :
nombre(nom), cuenta(cue), saldo(sal), tipoDeInteres(tipo)
{
  // Verificar los datos asignados
  asignarNombre(nom);
  asignarCuenta(cue);
  if (sal < 0) saldo = 0;
  asignarTipoDeInteres(tipo);
}

CCuenta::CCuenta(const CCuenta& c)
{
  *this = c;
}

CCuenta& CCuenta::operator=(const CCuenta& c)
{
  nombre = c.nombre;
  cuenta = c.cuenta;
  saldo = c.saldo;
  tipoDeInteres = c.tipoDeInteres;
  return *this;
}

bool CCuenta::asignarNombre(string nom)
{
  if (nom.length() != 0)
    nombre = nom;
  else
    cout << "Error: cadena nombre vac�a\n";
  return nom.length() != 0;
}

string CCuenta::obtenerNombre() const
{
  return nombre;
}

bool CCuenta::asignarCuenta(string cue)
{
  if (cue.length() != 0)
    cuenta = cue;
  else
    cout << "Error: cuenta no v�lida\n";
  return cue.length() != 0;
}

string CCuenta::obtenerCuenta() const
{
  return cuenta;
}

double CCuenta::estado() const
{
  return saldo;
}

void CCuenta::comisiones()
{
  return; // sin comisiones
}

double CCuenta::intereses()
{
  return 0.0; // sin intereses
}

bool CCuenta::ingreso(double cantidad)
{
  if (cantidad >= 0)
    saldo += cantidad;
  else
    cout << "Error: cantidad negativa\n";
  return cantidad >= 0;
}

void CCuenta::reintegro(double cantidad)
{
  if (saldo - cantidad < 0)
  {
    cout << "Error: no dispone de saldo\n";
    return;
  }
  saldo -= cantidad;
}

double CCuenta::obtenerTipoDeInteres() const
{
  return tipoDeInteres;
}

bool CCuenta::asignarTipoDeInteres(double tipo)
{
  if (tipo >= 0)
    tipoDeInteres = tipo;
  else
    cout << "Error: tipo no v�lido\n";
  return tipo >= 0;
}
//////////////////////////////////////////////////////////////////

