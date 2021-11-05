#include <cmath>
#include <class/Fraccion.h>
#include <class/SumaDFracciones.h>

SumaDFracciones::SumaDFracciones(Fraccion *op1,
                                 Fraccion *op2,
                                 Fraccion *rslt)
:F_op1(op1),F_op2(op2),F_rslt(rslt)
{/**Deliberadamente vac\'io*/}

SumaDFracciones::SumaDFracciones(Fraccion *op1,
                                 Fraccion *op2)
:F_op1(op1),F_op2(op2),F_rslt(new Fraccion((*op1+*op2)))
{/**Deliberadamente vac\'io*/}

/**Stub*/
std::ostream& operator<<(std::ostream& out,
                                SumaDFracciones SdFrhs){
 out << "Suma de Fracciones";
 return out;
}

std::string SumaDFracciones::to_string()
{
 char str[256];
 //*F_rslt = (*F_op1)+(*F_op2);
#if 0 //LMC 2021.10.26
 //F_rslt->simplificar();
 if ((F_rslt->signo())=='+') {
   sprintf(str,"\\frac{%d}{%d}+\\frac{%d}{%d}=\
\\frac{%u}{%u}",
           F_op1->n,F_op1->d,
           F_op2->n,F_op2->d,
           abs(F_rslt->n),abs(F_rslt->d)
           );
  }
  //else{}
#else
 F_rslt->simplificar();
 if ((F_rslt->signo())=='+') {
   sprintf(str,"\\frac{%d}{%d}+\\frac{%d}{%d}=\
\\frac{%u}{%u}=\\frac{%u}{%u}",
           F_op1->n,F_op1->d,
           F_op2->n,F_op2->d,
           abs(F_rslt->n),abs(F_rslt->d),
           F_rslt->N,F_rslt->D
           );
  }else{
   sprintf(str,"\\frac{%d}{%d}+\\frac{%d}{%d}=\
{-}\\frac{%u}{%u}={-}\\frac{%u}{%u}",
           F_op1->n,F_op1->d,
           F_op2->n,F_op2->d,
           abs(F_rslt->n),abs(F_rslt->d),
           F_rslt->N,F_rslt->D
           );
  }
#endif
  return std::string(str);
}
