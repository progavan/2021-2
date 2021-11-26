// cuenta_corriente.cpp - Definición de la clase CCuentaCorriente
#include <iostream>
#include "cuenta_corriente.h"
#include "fecha.h"
using namespace std;

//////////////////////////////////////////////////////////////////
// Clase CCuentaCorriente: clase derivada de CCuenta
//
CCuentaCorriente::CCuentaCorriente(string nom, string cue,
         double sal, double tipo, double imptrans, int transex) :
CCuenta(nom, cue, sal, tipo),
importePorTrans(imptrans), transExentas(transex)
{
  // Verificar datos
  transacciones = 0;
  asignarImportePorTrans(imptrans);
  asignarTransExentas(transex);
}

void CCuentaCorriente::decrementarTransacciones()
{
  transacciones--;
}

bool CCuentaCorriente::asignarImportePorTrans(double imptrans)
{
  if (imptrans >= 0)
    importePorTrans = imptrans;
  else
    cout << "Error: cantidad negativa\n";
  return imptrans >= 0;
}

double CCuentaCorriente::obtenerImportePorTrans() const
{
  return importePorTrans;
}

bool CCuentaCorriente::asignarTransExentas(int transex)
{
  if (transex >= 0)
    transExentas = transex;
  else
    cout << "Error: cantidad negativa\n";
    return transex >= 0;
}

int CCuentaCorriente::obtenerTransExentas() const
{
  return transExentas;
}

void CCuentaCorriente::ingreso(double cantidad)
{
  CCuenta::ingreso(cantidad);
  transacciones++;
}

void CCuentaCorriente::reintegro(double cantidad)
{
  CCuenta::reintegro(cantidad);
  transacciones++;
}

void CCuentaCorriente::comisiones()
{
  // Se aplican mensualmente por el mantenimiento de la cuenta
  int dia, mes, anyo;
  CFecha::obtenerFechaActual(dia, mes, anyo);
  if (dia == 1)
  {
    int n = transacciones - transExentas;
    if (n > 0) reintegro(n * importePorTrans);
    transacciones = 0;
  }
}

double CCuentaCorriente::intereses()
{
  int dia, mes, anyo;
  CFecha::obtenerFechaActual(dia, mes, anyo);
  if (dia != 1) return 0.0;

  // Acumular los intereses por mes sólo los días 1 de cada mes
  double interesesProducidos = 0.0;
  // Hasta 3000 euros al 0.5%. El resto al interés establecido.
  if (estado() <= 3000)
    interesesProducidos = estado() * 0.5 / 1200.0;
  else
  {
    interesesProducidos = 3000 * 0.5 / 1200.0 +
          (estado() - 3000) * obtenerTipoDeInteres() / 1200.0;
  }
  ingreso(interesesProducidos);
  // Este ingreso no debe incrementar las transacciones
  decrementarTransacciones();

  return interesesProducidos;
}
//////////////////////////////////////////////////////////////////
