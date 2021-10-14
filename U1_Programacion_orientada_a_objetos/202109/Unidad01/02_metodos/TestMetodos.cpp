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
 create_gif(imgFileName,G.to_string());
 gifFile.push_back(imgFileName);
 display_gui(gifFile,40,30);
#endif
 return 0;
}

//C:\Users\LMC\2021\REPOS_2021\2022_1_PROG_AVAN___2MV10\202109\Unidad01\02_metodos\TestMetodos.cpp|11|
//error: no match for 'operator<<' (
//operand types are 'std::ostream' {aka 'std::basic_ostream<char>'}
//and 'Fraccion')|

//incluir\Fraccion.h|22|error:
//'std::ostream& Fraccion::operator<<(std::ostream&, Fraccion)'
//must have exactly one argument|
