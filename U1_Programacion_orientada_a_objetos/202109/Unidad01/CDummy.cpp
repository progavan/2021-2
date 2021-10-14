#include <iostream>
using std::cout;
#if 1
#include "CDummy.h"
#else
#include <CDummy.h>
#endif

void CDummy :: dummy_func() {
  cout << "Variable CDummy::dummy_int = "
       << CDummy::dummy_int << "\n";
}

CDummy::CDummy(){
 dummy_int++;
}
