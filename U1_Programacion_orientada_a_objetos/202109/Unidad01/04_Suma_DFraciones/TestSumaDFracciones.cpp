#include <iostream>
#include <vector>
#include <class/SumaDFracciones.h>
#include <class/Fraccion.h>

std::vector<std::string> gifFile;

int main(){
 //std::string imgFileName;
 //imgFileName="file00.gif";
 //create_gif(imgFileName,
 //           "\\mbox{Suma de Fracciones}");
 //gifFile.push_back(imgFileName);
 Fraccion *Fop1 = new Fraccion(1,2);
 Fraccion *Fop2 = new Fraccion(1,4);
 Fraccion *F_r = new Fraccion(1,1);
 SumaDFracciones S(Fop1,Fop2,F_r);
 std::cout << S << "\n";
 return 0;
}/*end main()*/
