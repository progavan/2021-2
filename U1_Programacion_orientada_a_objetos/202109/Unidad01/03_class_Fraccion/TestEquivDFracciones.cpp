#include <iostream>
#include <vector>
#include <class/Fraccion.h>
#include <class/EquivDFraciones.h>
std::vector<std::string> gifFile;

int main(){
 std::string imgFileName;
 imgFileName="file00.gif";
 create_gif(imgFileName,
            //"\\mbox{FRACCIONES EQUIVALENTES}");
            "\\mbox{Fracciones Equivalentes}");
 gifFile.push_back(imgFileName);
#if 1
 Fraccion F(112,324);
 EquivDFracciones EdF(&F);
 imgFileName="file01.gif";
 create_gif(imgFileName,EdF.to_string());
 gifFile.push_back(imgFileName);
 display_gui(gifFile,40,30);
#else
 Fraccion F(112,-324);
 EquivDFracciones EdF(&F);
 imgFileName="file01.gif";
 create_gif(imgFileName,EdF.to_string());
 gifFile.push_back(imgFileName);
 display_gui(gifFile,40,30);
#endif
 return 0;
}/*end main()*/
