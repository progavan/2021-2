// test.cpp - Operaciones con la jerarquía de clases de CCuenta
#include <iostream>
#include "cuenta_ahorro.h"
#include "cuenta_corriente_plus.h"
using namespace std;

void visualizar(CCuentaAhorro&);

int main()
{
  CCuentaAhorro cuenta01(
                 "Un nombre", "Una cuenta", 10000, 3.5, 10);
  visualizar(cuenta01);

  CCuentaCorrienteConIn cuenta02;
  cuenta02.asignarNombre("cliente 02");
  cuenta02.asignarCuenta("1234567890");
  cuenta02.asignarTipoDeInteres(3.0);
  cuenta02.asignarTransExentas(0);
  cuenta02.asignarImportePorTrans(0.01);

  cuenta02.ingreso(20000);
  cuenta02.reintegro(5000);
  cuenta02.intereses();
  cuenta02.comisiones();
  cout << cuenta02.obtenerNombre() << endl;
  cout << cuenta02.obtenerCuenta() << endl;
  cout << cuenta02.estado() << endl;
}

void visualizar(CCuentaAhorro& cuenta)
{
  cout << cuenta.obtenerNombre() << endl;
  cout << cuenta.obtenerCuenta() << endl;
  cout << cuenta.estado() << endl;
  cout << cuenta.obtenerTipoDeInteres() << endl;
  cout << cuenta.intereses() << endl;
}
