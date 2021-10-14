#include <iostream>
#include <stdio.h>
using namespace std;
#include "incluir/CDummy.h"


extern int dummy_int;
//int CDummy::dummy_int;
int CDummy::dummy_int = 0;  /**Inicializaci\'on en alcance */
                            /**de archivo. */

void dummy_func();
void view_global_and_struc_vars();

int main() {
  dummy_int = 200;
  dummy_func();
  //CDummy::dummy_int = 300;
  CDummy::dummy_func();
  CDummy CD;                /**Se invoca al constructor*/
                            /**por defecto*/
  #if 0
  std::cout << "CDummy::dummy_int = "
            << CDummy::dummy_int     /* 1 */
            << "\n";
  std::cout << "dummy_int = "
            << dummy_int << "\n"; /* 200 */
  #else
  view_global_and_struc_vars();/* estruc ->1, global->200 */
  #endif
  CDummy cd;                /**Se invoca al constructor*/
                            /**por defecto*/
  view_global_and_struc_vars();/* estruc ->2, global->200 */
  std::cout << "CDummy::dummy_int = "
          #if 0
            << CD.dummy_int /* 2 (var de estruc/clase)*/
          #else
            << cd.dummy_int /* 2 (var de estruc/clase)*/
          #endif
            << "\n";
  CD.dummy_int = 0;
  std::cout << "CDummy::dummy_int = "
          #if 1
            << CD.dummy_int /* 0 (var de estruc/clase)*/
          #else
            << cd.dummy_int /* 0 (var de estruc/clase)*/
          #endif
            << "\n";
  CD.intDI = 10;
  cd.intDI = 20;
  std::cout << "CD.intDI = " << CD.intDI << std::endl;//10
  std::cout << "cd.intDI = " << cd.intDI << std::endl;//20
  return 0;
}/*end main()*/

