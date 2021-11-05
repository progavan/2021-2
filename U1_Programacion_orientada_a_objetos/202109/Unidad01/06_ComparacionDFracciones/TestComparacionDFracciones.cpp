#include <iostream>
#include <vector>
#include <class/EquivDFraciones.h>
#include <class/ComparacionDFracciones.h>
#include <class/Fraccion.h>
#include <common.h>

std::vector<std::string> gifFile;

int main(){
 std::string imgFileName;
 imgFileName="file00.gif";
 create_gif(imgFileName,
            "\\mbox{Comparacio$^{\\prime}$n de Fracciones}");
 gifFile.push_back(imgFileName);

 Fraccion *Fop1 = new Fraccion(1,2);
 Fraccion *Fop2 = new Fraccion(1,4);
 ComparacionDFracciones CDF(Fop1,Fop2);
 imgFileName="file01.gif";
 create_gif(imgFileName,CDF.to_string());
 gifFile.push_back(imgFileName);

 display_gui(gifFile,40,30);
 return 0;
}/*end main()*/
