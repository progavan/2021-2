// cuenta_ahorro.cpp - Definición de la clase CCuentaAhorro
#include <iostream>
#include "cuenta_ahorro.h"
#include "fecha.h"
using namespace std;

//////////////////////////////////////////////////////////////////
// Clase CCuentaAhorro: clase derivada de CCuenta
//
CCuentaAhorro::CCuentaAhorro(string nom, string cue, double sal,
                             double tipo, double mant) :
CCuenta(nom, cue, sal, tipo), cuotaMantenimiento(mant)
{
  asignarCuotaManten(mant); // verificar el dato mant
}

CCuentaAhorro::CCuentaAhorro(const CCuentaAhorro& ca) : CCuenta(ca)
{
  *this = ca;
}

CCuentaAhorro& CCuentaAhorro::operator=(const CCuentaAhorro& ca)
{
  CCuenta::operator=(ca);
  cuotaMantenimiento = ca.cuotaMantenimiento;
  return *this;
}

bool CCuentaAhorro::asignarCuotaManten(double cantidad)
{
  if (cantidad >= 0)
    cuotaMantenimiento = cantidad;
  else
    cout << "Error: cantidad negativa\n";
  return cantidad >= 0;
}

double CCuentaAhorro::obtenerCuotaManten() const
{
  return cuotaMantenimiento;
}

void CCuentaAhorro::comisiones()
{
  // Se aplican mensualmente por el mantenimiento de la cuenta
  int dia, mes, anyo;
  CFecha::obtenerFechaActual(dia, mes, anyo);
  
  if (dia == 1) reintegro(cuotaMantenimiento);
}

double CCuentaAhorro::intereses()
{
  int dia, mes, anyo;
  CFecha::obtenerFechaActual(dia, mes, anyo);

  if (dia != 1) return 0.0;
  // Acumular los intereses por mes sólo los días 1 de cada mes
  double interesesProducidos = 0.0;
  interesesProducidos = estado() * obtenerTipoDeInteres() / 1200.0;
  ingreso(interesesProducidos);
  
  // Devolver el interés mensual por si fuera necesario
  return interesesProducidos;
}

CCuentaAhorro *CCuentaAhorro::clonar()
{
  return new CCuentaAhorro(*this);
}
//////////////////////////////////////////////////////////////////

