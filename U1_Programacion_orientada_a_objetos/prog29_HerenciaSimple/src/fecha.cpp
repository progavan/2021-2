// fecha.cpp - Definición de los métodos de la clase CFecha
#include <iostream>
#include "ctime"
#include "fecha.h"
using namespace std;

// Definición del atributo fechaPorOmision
CFecha CFecha::fechaPorOmision = CFecha(1, 1, 2001);

CFecha::CFecha(int dd, int mm, int aaaa) : /* constructor */
dia(dd), mes(mm), anyo(aaaa)
{
  if (!fechaCorrecta())
  {
    // Fecha incorrecta. Se asigna la fecha por omisión.
    *this = fechaPorOmision;
  }
}

bool CFecha::bisiesto() const
{
  return ((anyo % 4 == 0) && (anyo % 100 != 0) || (anyo % 400 == 0));
}

void CFecha::asignarFecha(int dd, int mm, int aaaa)
{
  int d, m, a;
  obtenerFechaActual(d, m, a);
  // Asignar por omisión la fecha actual.
  if (dd) dia = dd; else dia = d;
  if (mm) mes = mm; else mes = m;
  if (aaaa) anyo = aaaa; else anyo = a;
}

void CFecha::obtenerFechaActual(int& dd, int& mm, int& aaaa)
{
  // Obtener la fecha actual.
  struct tm *fh;
  time_t segundos;
  time(&segundos);
  fh = localtime(&segundos);
  dd = fh->tm_mday; mm = fh->tm_mon+1; aaaa = fh->tm_year+1900;
}

void CFecha::obtenerFecha(int& dd, int& mm, int& aaaa) const
{
  dd = dia; mm = mes; aaaa = anyo;
}

bool CFecha::fechaCorrecta() const
{
  bool diaCorrecto, mesCorrecto, anyoCorrecto;

  anyoCorrecto = (anyo >= 1582); // ¿año correcto?
  mesCorrecto = (mes >= 1) && (mes <= 12); // ¿mes correcto?
  switch (mes)
  // ¿día correcto?
  {
    case 2:
      if (bisiesto())
        diaCorrecto = (dia >= 1 && dia <= 29);
      else
        diaCorrecto = (dia >= 1 && dia <= 28);
      break;
    case 4: case 6: case 9: case 11:
      diaCorrecto = (dia >= 1 && dia <= 30);
      break;
    default:
      diaCorrecto = (dia >= 1 && dia <= 31);
  }
  return diaCorrecto && mesCorrecto && anyoCorrecto;
}

const int& CFecha::obtenerDia() const
{
  return dia;
}

const int& CFecha::obtenerMes() const
{
  return mes;
}

const int& CFecha::obtenerAnyo() const
{
  return anyo;
}

void CFecha::asignarFechaPorOmision(int dd, int mm, int aaaa)
{
  fechaPorOmision.asignarFecha(dd, mm, aaaa);
}

