#ifndef PHONE_DIRECTORY_H
#define PHONE_DIRECTORY_H
#include <iostream>
#include "Directory_Entry.h"

/** Archivo de specificaci\'on para un directorio
    telef\'onico basado en un arreglo. */
class Phone_Directory
{
public:
/** Construir un directorio telef\'onico vacio*/
  Phone_Directory();
/** Destruir el directorio telef\'onico cuando
    ya no se necesita */
  ~Phone_Directory();
/** Cargar el archivo de datos que contiene el
    directorio, establecer una conexi\'on con
    la fuente de datos.
    @param source_name El nombre del archivo
                       (fuente de datos) con
                       las entradas/elementos del
                       directorio telef\'onico.
    */
void load_data(const std::string& source_name);
/** Buscar una entrada.
    @paranm name El nombre de la persona a buscar
    @return El n\'umero asociado con la persona o
            una cadena vac\'ia si el nombre no se
            encuentra en el directorio
*/
std::string lookup_entry(
            const std::string& name) const;
/** Modificar el n\'umero asociado con el nombre
    predeterminado para el nuevo n\'umero, o
    agregar una nueva entrada con el nombre <name>
    y el n\'umero <number>
    @param name El nombre de la persona
    @param number El nuevo n\'umero
*/
std::string add_or_change_entry(
            const std::string& name,
            const std::string& number);
/** Eliminar la entrada con un nombre espec\'ifico
    del directorio.
    @param name El nombre de la persona
    @return El nombr de la persona o una cadena
            vac\'ia si es que no se encuentra el
            nombre en el directorio
*/
std::string remove_entry(const std::string& name);
/** Escribir el contenido del directorio en el
    archivo de datos
*/
void save();

private:
/** Buscar el conjunto de entradas del directorio
    para el nombre
    @param name El nombre a ser encontrado
    @return El \'indice de la entrada que
            contiene el nombre, o -1 en caso de
            que el nombre no sea encontrado
*/
int find(const std::string& name_) const;
/** Agregar una nueva entrada con un nombre
    espec\'ifico y un n\'umero al arreglo de las
    entradas del directorio
    @param name El nombre a ser agregado
    @param number El n\'umero a ser agregado
*/
void add(const std::string& name,
         const std::string& number);
/** Eliminar la entrada con un \'indice
    espec\'ifico
    @param index El \'indice de la entrada a ser
                 eliminada
*/
void remove_entry(int index);
/** Crear un nuevo conjunto de las entradas del
    directorio con el doble de la capacidad
    actual.
*/
void reallocate();

/** Atributos */
/** El n\'umero de entradas en el directorio. */
  int size;
/** La capacidad actual del arreglo */
  int capacity;
/** Apuntador del arreglo que contiene los datos
    del directorio. */
    Directory_Entry *the_directory;
/** El nombre del archivo de datos que contiene
    los datos del directorio. */
  std::string source_name;
/** Bandera booleana para indicar si se
    modific\'o el directorio desde que fue
    cargado en memoria o para saber si guardarlo
    o no guardarlo. */
  bool modified;
};/*end class Phone_Directory*/

#endif // PHONE_DIRECTORY_H
