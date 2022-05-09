#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED
#include <vector>
#include "Sesion.h"

class Grupo{
 std::string NdG;       /**Nombre de Grupo*/
 std::string UdA;       /**Unidad de Aprendizaje*/
 std::vector<Sesion*> S;/**Sesion*/

public:
 Grupo(std::string ndg,std::string uda,Sesion *s0,Sesion *s1):
 NdG(ndg),UdA(uda){S.push_back(s0);S.push_back(s1);}
 Grupo(std::string ndg,std::string uda,Sesion *s0,Sesion *s1,Sesion *s2):
 NdG(ndg),UdA(uda){S.push_back(s0);S.push_back(s1);S.push_back(s2);}
friend std::ostream& operator<<(std::ostream& out,Grupo rhs)
{
#if 1
 out<<"GRUPO "<<rhs.NdG<<"\n";
#else
 out<<rhs.NdG<<"\n";
#endif
 for(size_t i=0;i<rhs.S.size();i++){
   out<<*(rhs.S[i])<<"\n";
 }
 return out;
}
 std::string get_NdG(){return NdG;}
 std::string get_UdA(){return UdA;}
 std::vector<Sesion*> get_S(){return S;}
};/*end class Grupo*/


#endif // GRUPO_H_INCLUDED
