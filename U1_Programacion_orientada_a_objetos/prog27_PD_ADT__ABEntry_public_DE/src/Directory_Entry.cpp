#include "Directory_Entry.h"

Directory_Entry::Directory_Entry()
:name(""),number("") /** inicializaciones */
{
  //name = "";   /** asignaci\'on */
  //number = ""; /** asignaci\'on */
}

Directory_Entry::Directory_Entry(
          std::string nombre,std::string numero)
:name(nombre),number(numero)
{
  //this->name=name;
  //this->number=number;
}

#if 1 //LMC 2021.11.16
Directory_Entry::~Directory_Entry()
{/**Deliberadamente vac\'io*/}
#endif // 1

std::string Directory_Entry::get_name(){
  return name;
}

std::string Directory_Entry::get_number(){
  return number;
}

void Directory_Entry::set_name(std::string name){
  this->name=name;
}

void Directory_Entry::set_number(
                      std::string number){
  this->number=number;
}
