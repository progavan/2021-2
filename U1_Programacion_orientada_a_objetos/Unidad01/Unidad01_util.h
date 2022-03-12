#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#if 1 //LMC 2022.03.04
#include <vector>
#include "Fecha.h"
#endif // 1
/** print_ident_data(__FILE__,argv[0]); en la funci\'on
 * main imprime datos de identificaci\'on: del archivo
 * fuente que contiene la funci\'on main, y el nombre
 * del archivo ejecutable.
 */
void print_ident_data(const char *,char *);
void print_ident_data_cpp(const char *,const char *);
void printf_fecha(Fecha *,Calendario *);
std::string left_zeroer(short hms);


void ordenar_fechas(std::vector<Fecha> vdf);
short day_in_year(short,short,short);
/** last_five_days_diff
 * calcula la longitud en d\'ias de un intervalo que
 * contiene las 5 fechas m\'as recientes contenidas
 * en el vector std::vector<Fecha> VecDFecha
 * pre: el vector VecDFecha contiene al menos 5 fechas.
 * pre: las 5 fechas m\'as recientes en el vector VecDFecha
 *      son del mismo a\~{n}o.
 */
short last_five_days_diff(std::vector<Fecha>);
void print_fechas_e_interv(std::vector<Fecha> VecDFecha);

#endif // UTIL_H_INCLUDED
