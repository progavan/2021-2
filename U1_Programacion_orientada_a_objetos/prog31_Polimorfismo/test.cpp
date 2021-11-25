// test.cpp - Polimorfismo
// Aplicación para trabajar con la clase CBanco y la jerarquía
// de clases derivadas de CCuenta
//
#include <iostream>
#include <vector>
#include <limits>
#include "banco.h"
#include "cuenta_ahorro.h"
#include "cuenta_corriente.h"
#include "cuenta_corriente+.h"
using namespace std;

double leerDato()
{
  double dato = 0.0;
  cin >> dato;
  while (cin.fail()) // si el dato es incorrecto, limpiar el
  {                  // búfer y volverlo a leer
    cout << '\a';
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
    cin >> dato;
  }
  // Eliminar posibles caracteres sobrantes
  cin.ignore(numeric_limits<int>::max(), '\n');
  return dato;
}

CCuenta *leerDatos(int op)
{
  CCuenta *obj;
  string nombre, cuenta;
  double saldo, tipoi, mant;
  cout << "Nombre.................: ";
  getline(cin, nombre);
  cout << "Cuenta.................: ";
  getline(cin, cuenta);
  cout << "Saldo..................: ";
  saldo = leerDato();
  cout << "Tipo de interés........: ";
  tipoi = leerDato();
  if (op == 1)
  {
    cout << "Mantenimiento..........: ";
    mant = leerDato();
    obj = new CCuentaAhorro(nombre, cuenta, saldo, tipoi, mant);
  }
  else
  {
    int transex;
    double imptrans;
    cout << "Importe por transacción: ";
    imptrans = leerDato();
    cout << "Transacciones exentas..: ";
    transex = (int)leerDato();

    if (op == 2)
      obj = new CCuentaCorriente(nombre, cuenta, saldo, tipoi,
                                  imptrans, transex);
    else
      obj = new CCuentaCorrienteConIn(nombre, cuenta, saldo,
                                      tipoi, imptrans, transex);
  }
  return obj;
}

int menu()
{
  cout << "\n\n";
  cout << "1.  Saldo\n";
  cout << "2.  Buscar siguiente\n";
  cout << "3.  Ingreso\n";
  cout << "4.  Reintegro\n";
  cout << "5.  Añadir\n";
  cout << "6.  Eliminar\n";
  cout << "7.  Mantenimiento\n";
  cout << "8.  Copia de seguridad\n";
  cout << "9.  Restaurar copia de seguridad\n";
  cout << "10. Salir\n";    
  cout << endl;
  cout << "   Opción: ";
  int op;
  do
    op = (int)leerDato();
  while (op < 1 || op > 10);
  return op;
}

int main()
{
  // Crear un objeto con cero elementos
  CBanco banco;
  CBanco *copiabanco = 0; // para la copia de seguridad
  CCuenta *cuen = 0;

  int opcion = 0, pos = -1;
  string cadenabuscar;
  string nombre, cuenta;
  double cantidad;
  bool eliminado = false;

  do
  {
    opcion = menu();
    switch (opcion)
    {
      case 1: // saldo
        cout << "Nombre total o parcial, o cuenta: ";
        getline(cin, cadenabuscar);
        pos = banco.buscar(cadenabuscar, 0);
        if (pos == -1)
          if (banco.longitud() != 0)
            cout << "búsqueda fallida\n";
          else
            cout << "no hay cuentas\n";
        else
        {
          cout << banco[pos]->obtenerNombre() << endl;
          cout << banco[pos]->obtenerCuenta() << endl;
          cout << banco[pos]->estado() << endl;
        }
        break;
      case 2: // buscar siguiente
        pos = banco.buscar(cadenabuscar, pos + 1);
        if (pos == -1)
          if (banco.longitud() != 0)
            cout << "búsqueda fallida\n";
          else
            cout << "no hay cuentas\n";
        else
        {
          cout << banco[pos]->obtenerNombre() << endl;
          cout << banco[pos]->obtenerCuenta() << endl;
          cout << banco[pos]->estado() << endl;
        }
        break;
      case 3: // ingreso
      case 4: // reintegro
        cout << "Cuenta: "; getline(cin, cuenta);
        pos = banco.buscar(cuenta, 0);
        if (pos == -1)
          if (banco.longitud() != 0)
            cout << "búsqueda fallida\n";
          else
            cout << "no hay cuentas\n";
        else
        {
          cout << "Cantidad: "; cantidad = leerDato();
          if (opcion == 3)
            banco[pos]->ingreso(cantidad);
          else
            banco[pos]->reintegro(cantidad);
        }
        break;
      case 5: // añadir
        cout << "Tipo de cuenta < 1-(CA), 2-(CC), 3-(CCI) >: ";
        do
          opcion = (int)leerDato();
        while (opcion < 1 || opcion > 3);
        cuen = leerDatos(opcion);
        banco.anyadir(cuen);
        delete cuen;
        break;
      case 6: // eliminar
        cout << "Cuenta: "; getline(cin, cuenta);
        eliminado = banco.eliminar(cuenta);
        if (eliminado)
          cout << "registro eliminado\n";
        else
          if (banco.longitud() != 0)
            cout << "cuenta no encontrada\n";
          else
            cout << "no hay cuentas\n";
        break;
      case 7: // mantenimiento
        for (pos = 0; pos < banco.longitud(); pos++)
        {
          banco[pos]->comisiones();
          banco[pos]->intereses();
        }
        break;
      case 8: // copia de seguridad
        if (banco.longitud() == 0) break;
        if (!copiabanco)
        {
          copiabanco= new CBanco(banco);
          if (copiabanco) cout << "copia realizada con éxito\n";
        }
        else
          cout << "existe una copia, restaurarla\n";
        break;
      case 9: // restaurar copia de seguridad
        if (!copiabanco) break;
        banco = *copiabanco;
        cout << "copia de seguridad restaurada\n";
        delete copiabanco;
        copiabanco = 0;
        break;
      case 10: // salir
        if (copiabanco) delete copiabanco;
        break;
    }
  }
  while(opcion != 10);
}

