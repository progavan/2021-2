#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <string.h>  /*strcmp()*/
#define NDEBUG
#include <assert.h>
#if 0//LMC 2022.03.04
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/util.h"
#else
#include "Calendario.h"
#include "Fecha.h"
#include "Unidad01_util.h"
#endif // 0
#define DISP_REC(d,m,a) VecDFecha.push_back(Fecha(d,m,a));\
 std::cout<<std::endl;\
 print_fechas_e_interv(VecDFecha);\
 std::cout<<std::endl;
#ifdef CONFIG_DISPOSAL_RECORDS
int main(int argc,char *argv[])
{
 //Calendario *Cal = new Calendario(2022);
 std::vector<Fecha> VecDFecha;
 VecDFecha.push_back(Fecha(19,1,2022));
 VecDFecha.push_back(Fecha(24,1,2022));
 VecDFecha.push_back(Fecha(4,2,2022));
 VecDFecha.push_back(Fecha(8,2,2022));
// VecDFecha.push_back(Fecha(14,2,2022));//<--
//
// print_ident_data(__FILE__,argv[0]);
// std::cout<<std::endl;
// print_fechas_e_interv(VecDFecha);
// std::cout<<std::endl;

 DISP_REC(14,2,2022)
 DISP_REC(22,2,2022)
 DISP_REC(28,2,2022)
 DISP_REC(2,3,2022)
 DISP_REC(7,3,2022)
 DISP_REC(9,3,2022)
 DISP_REC(23,3,2022)
 DISP_REC(28,3,2022)
 DISP_REC(6,4,2022)

 return 0;
}
#endif
/** pre: el vector de Fechas VecDFecha contiene al menos
 *  5 Fechas.
 */
void print_fechas_e_interv(std::vector<Fecha> VecDFecha){
 Calendario *Cal = new Calendario(VecDFecha[0].a);
 for (unsigned int i=VecDFecha.size()-5;i<VecDFecha.size();i++){
   printf_fecha(&VecDFecha[i],Cal);
 }
 std::cout<<std::endl;
 std::cout<<"Intervalo correspondiente a las 5 fechas previas: "
          <<last_five_days_diff(VecDFecha)+1<<" d\\'ias."<<std::endl;
}
