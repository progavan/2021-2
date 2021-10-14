#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
//#include "CDummy.h"
#include <CDummy.h>   /** add -Iruta_absoluta_o_relativa at make file
                          or at command line
                          or at command line. Example:
                          g++ -Iincluir/ -c file2.cpp -o file2.o */

int dummy_int;

void dummy_func() {
#if 0
  printf("Variable dummy_int = %d\n",dummy_int);
#endif // 0
  cout << "Variable CDummy::dummy_int = "
       << CDummy::dummy_int << "\n";
}

void view_global_and_struc_vars(){
  std::cout << "CDummy::dummy_int = "
            << CDummy::dummy_int
            << "\n";
  std::cout << "dummy_int = "
            << dummy_int << "\n";
}

