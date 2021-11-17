#ifndef DIRECTORY_ENTRY_H
#define DIRECTORY_ENTRY_H
#include <iostream>

class Directory_Entry
{
public:
  Directory_Entry();
  Directory_Entry(std::string,std::string);
 #if 1 //LMC 2021.11.16
  ~Directory_Entry();
 #endif // 1
  std::string get_name();
  std::string get_number();
  void set_name(std::string name);
  void set_number(std::string number);
protected:
  std::string name;
  std::string number;
private:
};

#endif // DIRECTORY_ENTRY_H
