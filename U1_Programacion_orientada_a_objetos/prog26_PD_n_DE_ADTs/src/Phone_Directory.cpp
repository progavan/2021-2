#include <fstream>
#include <cassert>
#if 1 //LMC 2021.11.16
#include <iostream>
#endif
using namespace std;
#include "Phone_Directory.h"
/** Construir un directorio telef\'onico vacio*/
Phone_Directory::Phone_Directory()
{
    size = 0;
    capacity = 5;
    the_directory = new Directory_Entry[capacity];
    //#if 1 //LMC 2021.11.16
    #if 0 //LMC 2021.11.16
    cout<<"the_directory has been initialized!\n";
    #endif // 1
}

Phone_Directory::~Phone_Directory(){
 #if 0 //LMC 2021.11.16
  delete the_directory;
 #else
  delete[] the_directory;
 #endif // 0
}

/** Cargar el archivo de datos que contiene el
    directorio, establecer una conexi\'on con
    la fuente de datos.
    @param source_name El nombre del archivo
                       (fuente de datos) con
                       las entradas/elementos del
                       directorio telef\'onico.
    La funci\'on para cargar el archivo de datos.
    pre: El almacenamiento del directorio se ha
         creado y se encuentra vac\'io. Si existe
         el archivo consistir\'a en pares
         name-number en l\'ineas adyacentes.
    post: Los datos a partir del archivo se
          cargan en el directorio.
    pre => post
*/
void Phone_Directory::load_data(
                const std::string& source_name)
{
  // Recordar el nombre de la fuente de datos
  // para utilizarlo al salvar
  this->source_name = source_name;
  // Crear una cadena de entrada para este archivo.
  ifstream in(source_name.c_str());
  if(in){// Si existe el flujo
    string name;
    string number;
    while(getline(in,name)){
        if(getline(in,number)){
            add(name,number);
        }
    }
    // Cerrar el archivo
    in.close();
  }
}

/** Agregar una entrada o modificar una entrada
    existente.
@param name El nombre de la persona que est\'a
            siendo agregada o modificada
@param number El nuevo n\'umero a ser asignado
@return El antiguo n\'umero o, si es una nueva
        entrada, una cadena vac\'ia
*/
std::string Phone_Directory::add_or_change_entry(
            const std::string& name_,
            const std::string& number_)
{
  std::string old_number = "";
  int index = find(name_);
  if(index != -1){// Si existe entrada con name
    old_number=the_directory[index].get_number();
    the_directory[index].set_number(number_);
  }else{ /** index es -1 */
    add(name_,number_);
  }
  modified = true;
  return old_number;
}

/** Buscar una entrada.
@param name El nombre de la persona
@return El n\'umero, Si no se encuentra en el
        directorio, una cadena vac\'ia
*/
std::string Phone_Directory::lookup_entry(
            const std::string& Name) const{
  int index = find(Name);
  if(index != -1){/** Si se encontr\'o name */
    return the_directory[index].get_number();
  }else{/** index es -1 */
    return "";
  }
}

#if 1 //LMC 2021.11.16
void Phone_Directory::mostrar(){
  for(int i=0;i<size; i++){
   std::cout<<the_directory[i].get_name()<<std::endl;
   std::cout<<the_directory[i].get_number()<<std::endl;
  }
}
#endif // 1

/** Funci\'on para guardar el directorio.
pre: el directorio ha sido cargado con datos
post: el archivo de datos tiene nuevamente el
      directorio actualizado bajo la forma
      nombre-numero en l\'ineas adyacentes.
      modified se vuelve a colocar en false.
*/
void Phone_Directory::save(){
 if(modified){ // If not modified, do nothing
  //Crear una cadena de salida.
  ofstream out(source_name.c_str());
  for(int i=0;i<size; i++){
   out<<the_directory[i].get_name()<<std::endl;
   out<<the_directory[i].get_number()<<std::endl;
  }
  //Cerrar la cadena de salida.
  out.close();
  modified=false;
 }
}

/** Buscar el conjunto para un nombre determinado.
@param name El nombre a ser encontrado
@return El \'indice de la entrada que contiene
        este nombre o -1, en caso de que el
        nombre no est\'e presente
*/
int Phone_Directory::find(const string& name_)const
{
 #if 0 //LMC 2021.11.16
  for(int i=0;i<size;i++){
    if(the_directory[i].get_name() == name_){
      return i;
    }
  }
 #else
  unsigned int siz = name_.length();
  unsigned int tsiz,j,sum=0;
  std::string tstr;

  for(int i=0;i<size;i++){
    tstr = the_directory[i].get_name();
    tsiz = tstr.length();
    if(tstr[tsiz-1] == 0x0d)/** txt files saved on Windows have */
      tsiz--;               /** 0x0d 0x0a  at the end of lines. */
  //#if 1 //LMC 2021.11.16
  #if 0 //LMC 2021.11.16
    std::cout<<"siz="<<siz<<" tsiz="<<tsiz<<"\n";
  #endif // 1
    if(tsiz != siz){
      continue;
    }else{
      for(j = 0;j < siz;j++){
        if(tstr[j] == name_[j]) sum++;
      }
      if (sum == siz){
        return i;
      }else{
        sum = 0;
        continue;
      }
    }
  }
 #endif // 0
  return -1;
}

/** Adicionar un nuevo par nombre-numero al
    directorio.
@param name El nombre a ser agregado
@param number El n\'umero a ser agregado
*/
void Phone_Directory::add(const std::string& name,
                      const std::string& number){
  if(size == capacity) {// If no room, reallocate
    reallocate();
  }
  // Incrementar size y agregar una nueva entrada.
  the_directory[size] =
                     Directory_Entry(name,number);
  size++;
}

/** Crear un nuevo arreglo de las entradas del
    directorio con el doble de la capacidad
    actual.
*/
void Phone_Directory::reallocate(){
  // Duplicar la capacidad.
  capacity *= 2;
  // Crear un nuevo arreglo del directorio.
  Directory_Entry *new_directory =
           new Directory_Entry[capacity];
  //Copiar el antiguo directorio al nuevo
  for(int i=0;i<size;i++){
    new_directory[i] = the_directory[i];
  }
  //Liberar la memoria ocupada por el
  //antiguo directorio
 #if 0 //LMC 2021.11.16.18.34
  delete the_directory;
  assert(3==0);
 #else
  delete[] the_directory;
 #endif // 0

  //Hacer que the_directory apunte al nuevo
  //directorio
  the_directory = new_directory;
}

/** Eliminar la entrada con un nombre espec\'ifico
    del directorio.
    @param name El nombre de la persona
    @return El nombre de la persona o una cadena
            vac\'ia si es que no se encuentra el
            nombre en el directorio
*/
std::string Phone_Directory ::
    remove_entry(const std::string& name){
  std::string str="";
  int index = find(name);
  if(index != -1){
    str = the_directory[index].get_name();
    remove_entry(index);
  }
  return str;
}

/**
  the_directory[] =
  { {Quincy,5511},{Mattew,5522},{Marcus,5533}   }
  (size tiene el valor 3)
  Si vamos a remover la entrada con \'indice 1,
  despu\'es de removerla, el arreglo the_directory
  debe quedar as\'i:
{{Quincy,5511},{Marcus,5533}}
  actualizar size (size debe disminuir en 1)
 */
void Phone_Directory::remove_entry(int index){
  // Ejercicio 2020.11.26
  // ESCRIBA SU CODIGO AQUI
}
