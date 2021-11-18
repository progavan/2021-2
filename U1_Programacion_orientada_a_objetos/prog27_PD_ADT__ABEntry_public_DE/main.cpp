/** main.cpp - Aplicaci\'on del directorio
telef\'onico que utiliza la consola I/O.

Para descargar solo un directorio de repositorio en github:
https://downgit.github.io/#/

*/
#include <iostream>
#include <fstream>
#include <limits>
#include <cassert>
#include "Phone_Directory.h"
#define SIZE_ARR(arr)   ((sizeof(arr))/(sizeof(arr[0])))
using namespace std;
// Declaraci\'on de las funciones
void process_commands(Phone_Directory&);
void do_add_change_entry(Phone_Directory&);
void do_lookup_entry(Phone_Directory&);
void do_remove_entry(Phone_Directory&);
void do_mostrar(Phone_Directory&);
void do_save(Phone_Directory&);

int main(int argc,char *argv[])
{
  if(argc < 2){
    cerr << "Se debe especificar el nombre del "
         << "archivo de datos que contiene el "
         << "directorio\n";
    return 1;
  }
  Phone_Directory DIR_TEL;
  DIR_TEL.load_data(argv[1]);
  process_commands(DIR_TEL);
  return 0;
}/*end main()*/

void process_commands(Phone_Directory&
                      el_directorio){
#if 0 //LMC 2021.11.16
  std::string commands[] = {
    "Agregar/Cambiar entrada",
    "Buscar entrada",
    "Borrar entrada",
    "Guardar directorio",
    "Salir",
  };
  const int NUM_COMMANDS = 5;
 #else
  char commands[][64] = {
    "Agregar/Cambiar entrada",
    "Buscar entrada",
    "Borrar entrada",
    "Mostrar directorio",
    "Guardar directorio",
    "Salir"
  };
  const int NUM_COMMANDS = SIZE_ARR(commands);
  assert(NUM_COMMANDS == 6);/** 2021.11.16 */
 #endif // 0
  int opcion = NUM_COMMANDS - 1;
  do{
    cout << "\nDIRECTORIO TELEFONICO" << endl;
    for(int i=0;i<NUM_COMMANDS;i++){
      cout<<i<<" "<<commands[i]<<"\n";
    }
  #if 0 //LMC 2021.11.18
    cout<<"Teclea una opcion (0,1,2,3,4,5): ";
  #else
    cout<<"Teclea una opcion (";
    for(int i=0;i<NUM_COMMANDS-1;i++){
      cout<<i<<",";
    }
    cout<<NUM_COMMANDS-1<<"): ";
  #endif // 0
    cin >> opcion;
    cin.ignore(numeric_limits<int>::max(),'\n');
    switch(opcion){
      case 0:{do_add_change_entry(el_directorio);
              break;
      }
      case 1:{do_lookup_entry(el_directorio);
              break;
      }
      case 2:{do_remove_entry(el_directorio);
              break;
      }
      case 3:{do_mostrar(el_directorio);
              break;
      }
      case 4:{do_save(el_directorio);
              break;
      }
      case 5:{do_save(el_directorio);
              break;
      }
    }
  }while(opcion != NUM_COMMANDS - 1);
}/*end process_commands()*/

void do_add_change_entry(
            Phone_Directory& el_directorio){
  std::string name;
  std::string number;
  std::string domicilio;
  cout<<"Teclea el nombre: ";
  getline(cin,name);
  cout<<"Teclea el n\\'umero: ";
  getline(cin,number);
  cout<<"Teclea el domicilio: ";
  getline(cin,domicilio);
  std::string old_number =
//el_directorio.add_or_change_entry(name,number);
el_directorio.add_or_change_entry(
                    name,number,domicilio);
  if(old_number != ""){
    cout<<name<<" ha sido cambiado(a) "
        <<"en el directorio.\n"
        <<"El n\\'umero anterior era "
        <<old_number<<"\n"
        <<"Domicilio: "<<domicilio<<"\n";
  }else{
    cout<<name<<" ha sido agregado(a) "
        <<" al directorio.\n";
  }
}

void do_lookup_entry(
        Phone_Directory& el_directorio){
  string name;
  string domicilio;
  int consultas;
  cout<<"Teclea el nombre: ";
  getline(cin,name);
  //assert(1==0);
  string number=el_directorio.lookup_entry(name);
  if(number != ""){
   domicilio =
     el_directorio.lookup_domicilio(name);
   consultas =
    el_directorio.lookup_num_TimesConsulted(name);
   cout<<"El n\\'umero de "<<name<<" es "
       <<number<<"\n"
       <<"Domicilio: "<<domicilio<<"\n"
       <<"Consultas de esta entrada: "
       <<consultas<<"\n";
  }else{
    cout<<name<<" no est\\'a en el directorio.\n";
  }
}

void do_remove_entry(
               Phone_Directory& el_directorio){
  string name;
  cout<<"Teclea el nombre a borrar: ";
  getline(cin,name);
  string number=el_directorio.lookup_entry(name);
  if(number != ""){
    el_directorio.remove_entry(name);
    cout<<"La entrada para "<<name<<" ha sido "
        <<"borrada del directorio.\n";
  }else{
    cout<<name<<" no est\\'a en el directorio.\n";
  }
}

void do_mostrar(Phone_Directory& el_directorio){
  cout<<"CONTENIDO DEL DIRECTORIO\n";
  el_directorio.mostrar();
}

void do_save(Phone_Directory& el_directorio){
  el_directorio.save();
}

