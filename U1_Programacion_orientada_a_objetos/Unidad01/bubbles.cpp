/**bubles.cpp*/
#include <vector>
#include <string>
using namespace std;
#if 0//LMC 2022.03.04
#include <Calendario.h>/*Add -I../CommonFiles in your make file*/
#include <Fecha.h>     /*Add -I../CommonFiles in your make file*/
#include <Dia.h>       /*Add -I../CommonFiles in your make file*/
#else
#include "Calendario.h"
#include "Fecha.h"
#endif // 0

#ifdef CONFIG_USING_CALENDARIO_FOR_PLANNING
void
ordenar_ddc(vector<Dia*>& vddc){
  Dia *dtmp;
  for(int j=vddc.size()-1;j>0;j--){
    for(int i=1;i<=j;i++){
      if(*(vddc[i-1]->f)>*(vddc[i]->f)){
        dtmp=vddc[i];
        vddc[i]=vddc[i-1];
        vddc[i-1]=dtmp;
      }
    }
  }
}
#endif // CONFIG_USING_CALENDARIO_FOR_PLANNING

void
ordenar_fechas(vector<Fecha> vdf){
 Fecha ftmp;
 for(int j=vdf.size()-1;j>0;j--){
   for(int i=1;i<=j;i++){
     if(vdf[i-1] > vdf[i]){
       ftmp=vdf[i];
       vdf[i]=vdf[i-1];
       vdf[i-1]=ftmp;
     }
   }
 }
}
