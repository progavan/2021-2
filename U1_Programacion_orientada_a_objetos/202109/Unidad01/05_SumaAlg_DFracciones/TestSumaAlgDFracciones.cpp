#include <iostream>
#include <vector>
#include <class/EquivDFraciones.h>
#include <class/SumaDFracciones.h>
#include <class/Fraccion.h>
#include <common.h>

std::vector<std::string> gifFile;

int main(){
 std::string imgFileName;
 imgFileName="file00.gif";
 create_gif(imgFileName,
            "\\mbox{Suma Algebra$^\\prime$ica de Fracciones}");
 gifFile.push_back(imgFileName);
 Fraccion *Fop1 = new Fraccion(1,2);
 Fraccion *Fop2 = new Fraccion(1,4);
 Fraccion Result = *Fop1 + *Fop2;

 SumaDFracciones S(Fop1,Fop2,&Result);

 imgFileName="file01.gif";
 create_gif(imgFileName,S.to_string());
 gifFile.push_back(imgFileName);

 Fraccion f1(-3,5),f2(2,7);
 Fraccion f3 = f1 + f2;
 SumaDFracciones f1plusf2(&f1,&f2,&f3);
 imgFileName="file03.gif";
 create_gif(imgFileName,f1plusf2.to_string());
 gifFile.push_back(imgFileName);

 Fraccion *Gop1 = new Fraccion(12,8);
 Fraccion *Gop2 = new Fraccion(-10,14);
 SumaDFracciones Gop1plusGop2(Gop1,Gop2);
 imgFileName="file04.gif";
 create_gif(imgFileName,Gop1plusGop2.to_string());
 gifFile.push_back(imgFileName);

 display_gui(gifFile,40,30);
 return 0;
}/*end main()*/
