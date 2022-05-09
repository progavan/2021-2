#include <stdlib.h>
#include <string.h>
#define CONFIG_USING_LIB_LOADFORMAT
#ifndef CONFIG_USING_LIB_LOADFORMAT
#include "Horario.h"
#else
#include "../U2_GUI/CodeblocksWorkspaceEleccionDCargaAcademica/01_IsGroupCompatibleWithThisHorario/Horario.h"
#endif
/**horizontal rule*/
void hrule(char ENC[],char sep,bool impr_inic_y_final){
  size_t index = 0;
  while(ENC[index]!='\0'){
    if (((index==0)||(ENC[index+1]=='\0'))&&impr_inic_y_final){
      printf("|");
      index++;
      continue;
    }
    if(sep==ENC[index]){
      printf("+");
    }else{
      printf("-");
    }
    index++;
  }
}

void show_tabla(std::string hfag[ROWS][COLS])
{
  size_t ndc;
  //for (size_t i=0;i<COLS;i++){ndc += 20;}
  /**num. de caracteres*/
  ndc = 20*(COLS-1)+hfag[0][0].length()+COLS+1;
  char enc[ndc+1]={'\0'};      /**encabezado*/
#if 0
  size_t index = 0;
  printf("\nndc=%li\n",ndc);
  while(index++<ndc){putchar('-');}
#else
/** Se forma la cadena
 * "|           |LUNES               |MARTES              |MIERCOLES           |JUEVES              |VIERNES             |"
 */
  char arr[COLS][ndc];

  sprintf(arr[0],"|%s",&hfag[0][0][0]);
  strcat(enc,arr[0]);
  for (size_t j=1;j<COLS;j++) {
    sprintf(arr[j],"|%-20s",&hfag[0][j][0]);
    strcat(enc,arr[j]);
  }
  enc[ndc-1]='|';enc[ndc]='\0';
  //printf("\n%s\n",enc);
#endif
// class CdIndexes { /**Conjunto de Indexes*/
//  size_t N;
//  short *sPt;
// public:
//  CdIndexes(char ENC[ndc+1]){
//   size_t i,k;
//   N = i = k = 0;
//   while(ENC[i]!='\0'){
//     if(ENC[i++]=='|'){N++;}
//   }
//   sPt = (short *)malloc(N*sizeof(short));
//   while(ENC[i]!='\0'){
//     if(ENC[i]=='|'){
//       *(sPt+k++)=i;
//     }
//     i++;
//   }
//  }
//  bool is_elem(short q){
//   for (size_t i=0;i<N;i++){
//     if(q==*(sPt+i)){
//       return true;
//     }
//   }
//   return false;
//  }
// };/*end class CdIndexes*/
//  CdIndexes CdI(enc);
  hrule(enc,'\a',false);
  printf("\n");
  for (size_t i=0;i<ROWS;i++) {
    for (size_t j=0;j<COLS;j++) {
      switch(j){
      case 0:{printf("|%s",&hfag[i][0][0]);break;}
      default:{printf("|%-20s",&hfag[i][j][0]);break;}
      }
    }
    printf("|\n");
    if (i < ROWS -1){
      hrule(enc,'|',true);printf("\n");
    }
  }
  hrule(enc,'\a',false);printf("\n");
}/*end show_tabla()*/
