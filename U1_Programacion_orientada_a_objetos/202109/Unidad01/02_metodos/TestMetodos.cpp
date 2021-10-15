#include <iostream>
#if 1 //2021.10.05
#include <vector>
std::vector<std::string> gifFile;
void display_gui(std::vector<std::string>& gifFile,
                 int x0,
                 int y0);
int create_gif(std::string gifFileName,
               std::string laTeXexp);
#endif

/**
 1: Se declara la clase Fraccion usando struct.
 0: Se declara la clase Fraccion usando class.
*/
#if 0 //2021.10.05
#include <Fraccion.h>
#else
#include <class/Fraccion.h>
#endif
using namespace std;
unsigned int MCD(int NUM,int DEN)
__attribute__((weak));
/**Stub*/
unsigned int MCD(int NUM,int DEN){
 return 1;
}

int main(){
 Fraccion F(112,324);
 cout << F; /**                        Jueves 2021.09.30
                IMPORTANTE: Adem\'as de sobrecargar el
                operador <<, si se usa compilaci\'on
                separada, DEBEMOS colocar el prototipo
        std::ostream& operator<<(std::ostream&,Fraccion)
        en el archivo Fraccion.h para evitar el error
        de compilaci\'on:
no match for 'operator<<' (operand types are 'std::ostream'
{aka 'std::basic_ostream<char>'} and 'Fraccion')
             */
 F.simplificar();
 cout << " = ";
 cout << F << endl;
 Fraccion G(112,-324);
 cout << G << " = ";
 G.simplificar();
 cout << G << endl;
#if 1 //2021.10.06
 std::string imgFileName="file01.gif";
 //std::cout<<"G.to_string(): "<<G.to_string()<<"\n";
 create_gif(imgFileName,G.to_string());
 //std::cout<<"G.to_string(): "<<G.to_string()<<"\n";
 #if 1
 gifFile.push_back(imgFileName);
 display_gui(gifFile,40,30);
 #endif
#endif
 return 0;
}


