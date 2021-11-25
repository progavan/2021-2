// cuenta_corriente+.cpp - Clase CCuentaCorrienteConIn
#include <iostream>
#include "cuenta_corriente+.h"
#include "fecha.h"
using namespace std;

//////////////////////////////////////////////////////////////////
// Clase CCuentaCorrienteConIn: clase derivada de CCuentaCorriente
//
// Métodos
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
  
  if (dia != 1 || estado() < 3000) return 0.0;
    
  // Acumular interés mensual sólo los días 1 de cada mes
  double interesesProducidos = 0.0;
  interesesProducidos = estado() * obtenerTipoDeInteres() / 1200.0;
  ingreso(interesesProducidos);
  // Este ingreso no debe incrementar las transacciones
  decrementarTransacciones(); 
  
  // Devolver el interés mensual por si fuera necesario
  return interesesProducidos;
}

CCuentaCorrienteConIn *CCuentaCorrienteConIn::clonar()
{
  return new CCuentaCorrienteConIn(*this);
}
//////////////////////////////////////////////////////////////////
