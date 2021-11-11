/** 07_Util/Test_Util.cpp */
#include <iostream>
#include <vector>
#include <class/EquivDFraciones.h>
#include <class/SumaDFracciones.h>
#include <class/ComparacionDFracciones.h>
#include <class/Fraccion.h>
#include <common.h>

int main(){
 Util::push("\\mbox{Fracciones Equivalentes}");
 Fraccion F(112,-324);
 EquivDFracciones EdF(&F);
 Util::push(EdF.to_string());

 Util::push("\\mbox{Suma Algebra$^\\prime$ica de Fracciones}");
 Fraccion *Fop1 = new Fraccion(-1,2);
 Fraccion *Fop2 = new Fraccion(1,4);
 Fraccion Result = *Fop1 + *Fop2;
 SumaDFracciones S(Fop1,Fop2,&Result);
 Util::push(S.to_string());

 Util::push("\\mbox{Comparacio$^{\\prime}$n de Fracciones}");
 ComparacionDFracciones CDF(Fop1,Fop2);
 Util::push(CDF.to_string());
 delete Fop1;
 delete Fop2;
 Fop1 = &Result;
 Fop2 = &F;
 ComparacionDFracciones CDF_1(Fop1,Fop2);
 Util::push(CDF_1.to_string());
 Fop1 = new Fraccion(112,-324);
 Fop2 = new Fraccion(-28,81);
 ComparacionDFracciones CDF_2(Fop1,Fop2);
 Util::push(CDF_2.to_string());

 delete Fop1;
 delete Fop2;
 display_gui(gifFile,40,30);
 return 0;
}/*end main()*/

