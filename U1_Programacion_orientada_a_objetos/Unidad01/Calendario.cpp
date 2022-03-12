#ifdef VISUAL_STUDIO_2017 /*Actually this DOES NOT work on Visual Studio*/
#include "stdafx.h"
#endif /*VISUAL_STUDIO_2017*/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> /*malloc()*/
#define NDEBUG
#include <assert.h>
using std::string;
using std::cout;
using std::endl;
using std::vector;
#include "Calendario.h"
#include "Fecha.h"
#if 0//LMC 2022.03.04
#include "Dia.h"
#include "Actividad.h"
#include "Asignacion.h"
#endif // 0

/* A\~no 2019*/         /*2019.10.20*/
/**El siguiente arreglo se fora colocando en cada fila los nombres de los
 * primeros siete d\'ias de cada mes del calendario. (2022.03.11)
 */
string ARREGLO[][7] = {
{ "Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo"}, /*enero*/
{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*febrero*/
{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*marzo*/
{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*abril*/
{ "Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes" }, /*mayo*/
{ "Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves" }, /*junio*/
{ "Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado" }, /*julio*/
{ "Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes" }, /*agosto*/
{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }, /*septiembre*/
{ "Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado","Domingo" }, /*octubre*/
{ "Jueves","Viernes","S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles" }, /*noviembre*/
{ "S\\'abado","Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes" }  /*diciembre*/
};

//#ifdef USING_ARREGLO
string MONTH[] = { "enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre" };
//#else
//static char MES[][32]={"static char MES[][32]",
//"enero","febrero","marzo","abril","mayo","junio","julio",
//"agosto","septiembre","octubre","noviembre","diciembre"
//};
//#endif /*USING_ARREGLO*/
/** Thursday 2020.01.30 */
char Calendario::MES[][32]={"static char MES[][32]",
"enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre"
};

void Calendario::mostrar_fechas(string d,string m){
  SetDIntType* sdi=obtener_nums_ddia(d,m);
  print_SetDIntYFecha(d,m,sdi);
}

void Calendario::print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}
int Calendario::index_delmes(string month){
  if(month=="enero")       return 0;
  if(month=="febrero")     return 1;
  if(month=="marzo")       return 2;
  if(month=="abril")       return 3;
  if(month=="mayo")        return 4;
  if(month=="junio")       return 5;
  if(month=="julio")       return 6;
  if(month=="agosto")      return 7;
  if(month=="septiembre")  return 8;
  if(month=="octubre")     return 9;
  if(month=="noviembre")   return 10;
  if(month=="diciembre")   return 11;
  return -1; /*Para tratar de detectar alg\'un error*/
}/*end int Calendario::index_delmes(string month)*/

int Calendario::primera_fecha_delmes(string day,int i){
if(ARREGLO[i][0]==day) return 7;
if(ARREGLO[i][1]==day) return 1;
if(ARREGLO[i][2]==day) return 2;
if(ARREGLO[i][3]==day) return 3;
if(ARREGLO[i][4]==day) return 4;
if(ARREGLO[i][5]==day) return 5;
if(ARREGLO[i][6]==day) return 6;
return -1; /*Para tratar de detectar alg\'un error*/
}/*end int Calendario::primera_fecha_delmes(string day,int i)*/

SetDIntType* Calendario::obtener_nums_ddia(string d, string m){
             SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
             int i,j=0; /* index de l mex es el arreglo*/
             i=index_delmes(m);
             if(i>=0 && i<12){
                     j=primera_fecha_delmes(d,i);
                     }
                     fill_SDIT(i,j,r);
                     return r;
}
void Calendario::fill_SDIT(int i,int j,SetDIntType* r){
 int diasdmes;
 if (i==0)  diasdmes=31;
 if (i==1)  diasdmes=29;/**Creo que esto lo escrib\'i en 2016,
                           el cual fue bisiesto */
 if (i==2)  diasdmes=31;
 if (i==3)  diasdmes=30;
 if (i==4)  diasdmes=31;
 if (i==5)  diasdmes=30;
 if (i==6)  diasdmes=31;
 if (i==7)  diasdmes=31;
 if (i==8)  diasdmes=30;
 if (i==9)  diasdmes=31;
 if (i==10) diasdmes=30;
 if (i==11) diasdmes=31;
 int cnt=0;
 for (int k=j; k<=diasdmes; k+=7)
 {
     r->intPt[cnt]=k;
     cnt++;
 }
 r->n=cnt-1;
}

bool Calendario::esta_incluido(string d,vector<string> dias){
  bool ret=false;
  for(unsigned int i=0;i<dias.size();i++){
    if(d==dias[i]){
      ret=true;
      break;
    }
  }
  return ret;
}

/** 2022.03.11, La macro CONFIG_USING_CALENDARIO_FOR_PLANNING
 * eventualmente se tendr\'ia que definir (a veces) en el archivo
 * include/generated/autoconf.h
 * generado con el comando:
 * ./scripts/kconfig/conf --silentoldconfig Kconfig
 * (si es que se selecciona la opci\'on de configuraci\'on
 *  USING_CALENDARIO_FOR_PLANNING al ejecutar la herramienta
 *  make menuconfig al configurar el proyecto --se puede agregar
 *  una herramienta [Tool] en codeblocks con name 'make menuconfig'
 *  para ejecutar:
 *  kconfig-mconf Kconfig y
 *  ./scripts/kconfig/conf --silentoldconfig Kconfig
 *  en la construcci\'on de
 *  un objetivo 'menuconfig' en un archivo Makefile). Digo que
 * eventualmente se tendr\'ia que definir en alg\'un archivo
 * include/generated/autoconf.h, porque hasta ahora (2022.03.11),
 * creo que no he colocado
 * config USING_CALENDARIO_FOR_PLANNING
 *    bool "..."
 *    default n
 *    help
 *      ...
 * en casi ning\'un archivo Kconfig. (De hecho, en el \'unico
 * archivo Kconfig en el que he incluido
 * config USING_CALENDARIO_FOR_PLANNING,
 * org_progavan/2021-2/U1_Programacion_orientada_a_objetos/Unidad01,
 * en la ayuda (help) tengo documentadas las razones por las que esta
 * opci\'on rompe ese proyecto Unidad01).
 * En definitiva, esta guarda la coloqu\'e para que al usar
 * este archivo en el proyecto Unidad01 del curso
 * Programaci\'on Avanzada (UPIITA-IPN, 2022_2) no se
 * resuelva el m\'etodo
 * bool Calendario::esta_incluido(Fecha* fPt,vector<Dia*> dnl),
 * ya que si lo incluyo, tendr\'ia que incluir en el proyecto
 * Unidad01 alguna declaraci\'on e implementaci\'on de la clase
 * Dia, y por el momento no he incluido esta clase en el proyecto
 * Unidad01 compartido a los discentes en Materiales de Clase en
 * MS Teams, 2022_2_M217_PROGA_2MV4. Viernes 2022.03.11.
 */
#ifdef CONFIG_USING_CALENDARIO_FOR_PLANNING
bool Calendario::esta_incluido(Fecha* fPt,vector<Dia*> dnl){
  bool ret=false;
  for(unsigned int i=0;i<dnl.size();i++){
    if(*(dnl[i]->f)==*fPt){
      ret=true;
      break;
    }
  }
  return ret;
}
#endif // CONFIG_USING_CALENDARIO_FOR_PLANNING

bool Calendario::esta_incluido(Fecha* fPt,vector<Fecha*> FDdnl){
  bool ret=false;
  for(unsigned int i=0;i<FDdnl.size();i++){
    if(*FDdnl[i]==*fPt){
      return true;
    }
  }
  return ret;
}

/**
 devuelve la cantidad de fechas entre fi y ff que corresponden a los
 dias en el vector dias.
 */
int Calendario::cant_dFechas(Fecha *fi,Fecha *ff,vector<string> dias){
  int im=fi->m,id=fi->d,cnt=0;
  /*cantidades de dias de los meses (2016)*/
  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
inic:
  if((im!=ff->m)||(id!=ff->d)){
    if(esta_incluido(ARREGLO[im][id%7],dias)){
      cnt++;
    }
    if((id+1)<=TamM[im]){
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
    cnt++;
  }
  return cnt;
}

/**
 * @param fi:apuntador a fECHA iNICIAL
 * @param ff:apuntador a fECHA fINAL
 * pre: Ambas fechas corresponden al mismo a\~{n}o
 */
vector<Fecha*> Calendario::get_Fechas(Fecha *fi,Fecha *ff,vector<string> dias){
  //int im=fi->m,id=fi->d,cnt=0; /*iNDICE del mES, iNDICE del dIA*/
  int im=fi->m,id=fi->d; /*iNDICE del mES, iNDICE del dIA*/
  vector<Fecha*> vdf;
  /** Cantidades de dias de los meses de los a\~nos:
   *  (2016--2016 fue bisiesto--,2017,2018,2019)
   */
#ifdef USING_ARREGLO
  int TamM[]={31,29,31,30,31,30,31,31,30,31,30,31};
#else
#ifdef LEAPYEAR
int TamM[]={0,31,29,31,30,31,30,31,31,30,31,30,31};/*para a\~nos bisiestos*/
#else
int TamM[]={0,31,28,31,30,31,30,31,31,30,31,30,31};/*para a\~nos no bisiestos*/
#endif /*LEAPYEAR*/
#endif /*USING_ARREGLO*/
inic:
  if((im!=ff->m)||(id!=ff->d)){
#ifdef USING_ARREGLO
    if(esta_incluido(ARREGLO[im][id%7],dias)){
#else
    if(esta_incluido(get_day_name(new Fecha(id,im,fi->a)),dias)){/**2020.01.30*/
#ifndef NDEBUG
  printf("La fecha %s %d de %s de %d SI ESTA INCLUIDA!\n"
        ,get_day_name(fi)             /*2020.01.30*/
        ,fi->d
        ,MES[fi->m]
        ,fi->a);
#endif /*NDEBUG*/
#endif /*USING_ARREGLO*/
      vdf.push_back(new Fecha(id,im,fi->a));
    }
    if((id+1)<=TamM[im]){
      id++;
    }else{
      id=1;im++;
    }
    goto inic;
  }
#ifdef USING_ARREGLO
  if(esta_incluido(ARREGLO[ff->m][ff->d%7],dias)){
#else
    if(esta_incluido(get_day_name(ff),dias)){   /**2020.01.30*/
#endif /*USING_ARREGLO*/
    vdf.push_back(new Fecha(ff->d,ff->m));
  }
  return vdf;
}/*end Calendario::get_Fechas()*/

/** Vease comentario acerca del uso de esta guarda arriba */
#ifdef CONFIG_USING_CALENDARIO_FOR_PLANNING
/** Usando el vector de Fechas vdf y el vector de Dias no laborables
 * dnl, construye un vector de Dias laborables (los dias de clase para
 * los que se planificar\'an actividades) este vector de Dias laborables.
 * @param vdf:vector de apuntadores a Fechas de los dias de la semana (VyG.
 *            "Lunes" y "Viernes" ) que normalmente hay clase desde una
 *            Fecha inicial hasta una Fecha final.
 * @param dnl:vector de apuntadores a Dias
 */
vector<Dia*> Calendario::get_Dias_DC(vector<Fecha*> vdf,vector<Dia*> dnl){
  vector<Dia*> vddc;
  for(unsigned int i=0;i<vdf.size();i++){
    if(!esta_incluido(vdf[i],dnl)){
      vddc.push_back(new Dia(vdf[i]));
    }
  }
  return vddc;
}

void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT){
  /*i para recorrer los dias y j para recorrer las actividades*/
  //int i=0,j=0;
  unsigned int i=0,j=0;
  assert(DIA[i]!=NULL);
  assert(ACT[j]!=NULL);
#ifndef NDEBUG
  printf("void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT)\n");
#ifndef USING_ARREGLO
  printf("i=%3d j=%3d: %s %d/%s/%d DIA[i]->TD=%5.2f ACT[j]->TR=%5.2f\n",
         i,j,get_day_name(DIA[i]->f),DIA[i]->f->d,MES[DIA[i]->f->m],
         DIA[i]->f->a,DIA[i]->TD,ACT[j]->TR);
#endif /*USING_ARREGLO*/
#endif /*NDEBUG*/
inicio:
  if(ACT[j]->TR<=DIA[i]->TD){
#ifndef NDEBUG
  printf("i=%3d j=%3d: DIA[i]->TD=%5.2f ACT[j]->TR=%5.2f\n",
         i,j,DIA[i]->TD,ACT[j]->TR);
#endif /*NDEBUG*/
    DIA[i]->TD-=ACT[j]->TR;
	if(ACT[j]->TR>0)
      DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR));
    j++;
	/** 2018.08.20*/
	if (DIA[i]->TD < 0.01) { DIA[i]->TD = 0; }
	/** */
    if(DIA[i]->TD==0)
      i++;
  }else{
    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD));
    ACT[j]->TR-=DIA[i]->TD;
	/** 2018.08.20*/
	if (ACT[j]->TR < 0.01) { ACT[j]->TR = 0; }
	/** */
    i++;
  }
  if( !( (i==DIA.size())||(j==ACT.size()) ) )
    goto inicio;
}//end void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT)
#endif // CONFIG_USING_CALENDARIO_FOR_PLANNING
//
//void Calendario::planear(vector<Dia*> DIA,vector<Actividad*> ACT,vector<Alumno*> Alum){
//  int i=0,j=0;/*i para recorrer los dias y j para recorrer las actividades*/
//  int k=0,nda;/*en nda el constructor de Asignacion colocara cuantas Asignaciones van.*/
//inicio:
//  if(ACT[j]->TR<=DIA[i]->TD){
//
//    DIA[i]->TD-=ACT[j]->TR;
//    DIA[i]->A.push_back(new Asignacion(ACT[j],ACT[j]->TR,Alum[k],&nda));
//    j++;
//    if(DIA[i]->TD==0)
//      i++;
//  }else{
//    DIA[i]->A.push_back(new Asignacion(ACT[j],DIA[i]->TD,Alum[k],&nda));
//    ACT[j]->TR-=DIA[i]->TD;
//    i++;
//  }
//  if(nda>=3){
//    k=(k+1)%NUMDALUMNOS;
//  }
//  if( !( (i==DIA.size())||(j==ACT.size()) ) )
//    goto inicio;
//}
//*/

/** Devuelve el nombre del dia ("Lunes","Martes","Mi\\'ercoles",
 * "Jueves","Viernes","S\\'abado","Domingo") correspondiente a la
 * fecha a la que apunta f_Pt.
 * X=D+M+A+(1/4)A+S
 * D:es el n\'umero del d\'ia de la fecha
 * M:es el c\'odigo del mes
 * A:es el n\'umero del a\~no (dos d\'igitos)
 * (1/4)A: es la cuarta parte del a\~no (divisi\'on entera)
 * S:es el c\'odigo del siglo
 */
#ifdef USAR_STRING
static std::string day_name[]={
#else
static char day_name[][32]={
#endif
"Domingo","Lunes","Martes","Mi\\'ercoles","Jueves","Viernes","S\\'abado"
};
int Month_Code[]={
#ifdef LEAPYEAR
/*enero*/      0,
/*febrero*/    3,
/*marzo*/      4,
/*abril*/      7,
/*mayo*/       2,
/*junio*/      5,
/*julio*/      7,
/*agosto*/     3,
/*septiembre*/ 6,
/*octubre*/    1,
/*noviembre*/  4,
/*diciembre*/  6
//};
#else
//int Month_Code[]={
/*enero*/      0,
/*febrero*/    3,
/*marzo*/      3,
/*abril*/      6,
/*mayo*/       1,
/*junio*/      4,
/*julio*/      6,
/*agosto*/     2,
/*septiembre*/ 5,
/*octubre*/    0,
/*noviembre*/  3,
/*diciembre*/  5
#endif /*LEAPYEAR*/
};
//int Century_Code[]={
/*1600 - 1699:6,*/
/*1700 - 1799:4,*/
/*1800 - 1899:2,*/
/*1900 - 1999:0,*/
/*2000 - 2099:6, se repiten cada 400 a\~nos*/
//};
/** En caso de error, devuelve -1*/
int Century_Code(int year)
{
  if((year>=1600)&&(year<=1699)){
    return 6;
  }else if((year>=1700)&&(year<=1799)){
    return 4;
  }else if((year>=1800)&&(year<=1899)){
    return 2;
  }else if((year>=1900)&&(year<=1999)){
    return 0;
  }else if((year>=2000)&&(year<=2099)){
    return 6;  /*se repiten cada 400 a\~nos*/
  }
  return -1;   /** En caso de error, devuelve -1*/
}/*end Century_Code()*/

#ifdef USAR_STRING
std::string
#else
char *
#endif
Calendario::get_day_name(Fecha *f_Pt)
{
#ifdef USAR_STRING
  std::string result=string(day_name[0]);
#else
  char *result=day_name[0];
#endif
  int X,/*n\'umero a calcular*/
      D,/*n\'umero del d\'ia de la fecha*/
      M,/*c\'odigo del mes*/
 //     A,/*n\'umero del a\~no (dos d\'igitos)*/
      /*(1/4)A, cuarta parte del a\~no (divisi\'on entera)*/
      Aover4,
      S;/*c\'odigo del siglo*/
#ifdef LMC_TEST_20200130_2
  f_Pt->a=anio;
#endif /*LMC_TEST_20200130_2*/
  D=f_Pt->d;
  M=Month_Code[f_Pt->m-1];
//  A=f_Pt->a%100;
//  A=
//  S=Century_Code(f_Pt->a);
int obtener_S(int);
  S=obtener_S(f_Pt->a);
int obtener_Aover4(int);
  Aover4=obtener_Aover4(f_Pt->a);
#ifndef NDEBUG
  printf("%s: line:%d\n",__FILE__,__LINE__);
  printf("D=%d\nM=%d\nS=%d\n",D,M,S);
#endif /*NDEBUG*/
  //X=D+M+A+A/4+S;
  X=D+M+Aover4+S;
#ifndef NDEBUG
  printf("X=%d\n",X);
#endif /*NDEBUG*/
  X=X%7;
  result=day_name[X];
  return result;
}/*end Calendario::get_day_name(Fecha *f_Pt)*/

/*Para obtener A*/
int obtener_S(int a){
  return (a-1)%7;
}

int obtener_Aover4(int a){
  return ((a-1)/4-(3*((a-1)/100+1)/4))%7;
}


