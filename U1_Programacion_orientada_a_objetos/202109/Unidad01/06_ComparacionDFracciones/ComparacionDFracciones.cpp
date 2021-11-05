#include <cmath>
#include <class/Fraccion.h>
#include <class/ComparacionDFracciones.h>
/**Stub*/
ComparacionDFracciones::ComparacionDFracciones(Fraccion *op1,
                                               Fraccion *op2)
:F_op1(op1),F_op2(op2),rel('>')
{}

/**Stub*/
std::string ComparacionDFracciones::to_string()
{
 char str[256];
 if ((get_rel())=='>') {
   sprintf(str,"\\frac{%d}{%d}{%c}\\frac{%d}{%d}",
           F_op1->n,F_op1->d,
           rel,
           F_op2->n,F_op2->d);
  }//else{
  //}
  return std::string(str);
}

char ComparacionDFracciones::get_rel()
{
 return rel;
}

