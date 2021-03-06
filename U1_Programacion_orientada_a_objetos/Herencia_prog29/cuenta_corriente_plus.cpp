// cuenta_corriente_plus.cpp - Clase CCuentaCorrienteConIn
#include <iostream>
#include "cuenta_corriente_plus.h"
#include "fecha.h"
using namespace std;

//////////////////////////////////////////////////////////////////
// Clase CCuentaCorrienteConIn: clase derivada de CCuentaCorriente
//
// M�todos
CCuentaCorrienteConIn::CCuentaCorrienteConIn(string nom,
         string cue, double sal, double tipo,
         double imptrans, int transex) :
CCuentaCorriente(nom, cue, sal, tipo, imptrans, transex)
{
}

double CCuentaCorrienteConIn::intereses()
{
  int dia, mes, anyo;
  CFecha::obtenerFechaActual(dia, mes, anyo);
#ifdef REVISAR_FECHA
  if (dia != 1 || estado() < 3000) return 0.0;
#endif /*REVISAR_FECHA*/
  // Acumular inter�s mensual s�lo los d�as 1 de cada mes
  double interesesProducidos = 0.0;
  interesesProducidos = estado() * obtenerTipoDeInteres() / 1200.0;
  ingreso(interesesProducidos);
  // Este ingreso no debe incrementar las transacciones
  decrementarTransacciones();

  // Devolver el inter�s mensual por si fuera necesario
  return interesesProducidos;
}
//////////////////////////////////////////////////////////////////

