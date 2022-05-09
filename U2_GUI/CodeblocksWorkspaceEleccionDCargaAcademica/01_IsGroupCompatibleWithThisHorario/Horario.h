#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED
#include <cstdio>
#include "Grupo.h"
#define ROWS   10
#define COLS    6

class Horario{
 std::vector<Grupo> G;
public:
static std::string HFaG[ROWS][COLS];/**Atributo de clase*/
//public:
 void add(Grupo g){G.push_back(g);}
 short get_cardinality(){return G.size();}
friend std::ostream& operator<<(std::ostream& out,Horario rhs)
{
 out<<"HORARIO: ";
 for (size_t i=0;i<rhs.G.size();i++){
   out<<rhs.G[i].get_NdG()<<" ";
 }
 out<<"\n";
 for (size_t i=0;i<rhs.G.size();i++){
#if 1
   out<<"out<<rhs.G["<<i<<"]<<\"\\n\";\n";
#endif // 1
   out<<rhs.G[i]<<"\n";
 }
 return out;
}
 /** is_group_compatible 'is group compatible
  * with this Horario'
  */
 bool is_group_comp(Grupo g)
 {
  std::vector<Sesion*> Sd_g=g.get_S();
  for (size_t i=0;i<Sd_g.size();i++) {
    for (size_t j=0;j<G.size();j++) {
      std::vector<Sesion*> SdG_j=G[j].get_S();
      for (size_t k=0;k<SdG_j.size();k++) {
        if (*Sd_g[i]==*SdG_j[k])
          return false;
      }
    }
  }
  return true;
 }
 std::vector<Grupo> get_G(){return G;}
 void show()
 {
  short m,n;
  std::vector<Sesion*> SdG;
  for (size_t i=0;i<G.size();i++) {
    SdG=G[i].get_S();
    for (size_t j=0;j<SdG.size();j++) {
      m=SdG[j]->get_X();
      n=SdG[j]->get_Y();
//      std::cout<<"i="<<i<<"\tj="<<j<<"\tm="<<m<<"\tn="<<n<<"\n";
      HFaG[m][n]=G[i].get_NdG()+" "+G[i].get_UdA()+" ";
    }
  }
  for (size_t i=0;i<ROWS;i++) {
    for (size_t j=0;j<COLS;j++) {
      switch(j){
      case 0:{printf("|%s",&HFaG[i][0][0]);break;}
      default:{printf("|%-20s",&HFaG[i][j][0]);break;}
      }
    }
    printf("|\n");
  }
 }/*end show()*/
//static std::string [ROWS][COLS] get_HFaG(){return HFaG;}
};/*end class Horario*/


#endif // HORARIO_H_INCLUDED
