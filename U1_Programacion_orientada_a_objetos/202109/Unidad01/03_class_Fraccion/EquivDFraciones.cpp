#include <cmath>
#include <class/Fraccion.h>
#include <class/EquivDFraciones.h>
/**
 0: Se inicializa el atributo P_Pt en el cuerpo
    del constructor.
 1: Se utiliza un inicializador.
 */
EquivDFracciones::EquivDFracciones(Fraccion *p)
#if 0
:F_Pt(p){/** Deliberadamente vac\'io. */}
#else
{
 F_Pt = p;
}
#endif

std::string EquivDFracciones::to_string()
{
 char str[128];
 //std::string R="";
 F_Pt->simplificar();
 if ((F_Pt->signo())=='+') {
   sprintf(str,"\\frac{%u}{%u}=\\frac{%u}{%u}\
\\mbox{\\ \\ \\ \\ \\ \\ MCD}(%u,%u)=%u",
           abs(F_Pt->n),abs(F_Pt->d),
           F_Pt->N,F_Pt->D,
           abs(F_Pt->n),abs(F_Pt->d),
           F_Pt->MCD(abs(F_Pt->n),abs(F_Pt->d))
           );
 }else{
   sprintf(str,"{-}\\frac{%u}{%u}={-}\\frac{%u}{%u}\
\\mbox{\\ \\ \\ \\ \\ \\ MCD}(%u,%u)=%u",
           abs(F_Pt->n),abs(F_Pt->d),
           F_Pt->N,F_Pt->D,
           abs(F_Pt->n),abs(F_Pt->d),
           F_Pt->MCD(abs(F_Pt->n),abs(F_Pt->d))
           );
 }
 return std::string(str);
}
