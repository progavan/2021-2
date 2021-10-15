/**                   Jueves 14 de octubre de 2021.
    0: Con 0 se utiliza la definici\'on de la clase
       Fraccion con la palabra reservada class.
    1: Con 1 se utiliza la definici\'on de la clase
       Fraccion con la palabra reservada struct.
    Pero con 1, se rompe el objetivo 02_metodos y
    objetivos posteriores. Por otra parte, con 0 no
    se rompe el objetivo 01_constructores (si en la
    clase Fraccion se incluye el constructor por
    defecto -- Fraccion() --).
 */
#if 0 //2021.10.05
#include <Fraccion.h>
#else
#include <class/Fraccion.h>
#endif

unsigned int MCD(int NUM,int DEN);

Fraccion::Fraccion(int num,int den)
{
  N=abs(n = num);
  D=abs(d = den);
}
#if 1
Fraccion::Fraccion()
{ /** Deliberadamente vac\'io. */ }
#endif // 0

Fraccion Fraccion::operator+(Fraccion rhs)
{
  Fraccion R(0,1);                /**  n/d + rhs.n/rhs.d */
  int den_com = d * rhs.d;
  int n_r = (den_com/d)*n + (den_com/rhs.d)*rhs.n;
  R.n = n_r;
  R.d = den_com;
  return R;
}

std::ostream& operator << (std::ostream& out,Fraccion rhs){
 char sgn_num,sgn_den;
 sgn_num = (rhs.n>=0)?'+':'-';
 sgn_den = (rhs.d>=0)?'+':'-';
 out << ((sgn_num==sgn_den)?' ':'-')
     << rhs.N << "/"<< rhs.D;
 return out;
}

/**Stub*/
#if 0 /** Con 0, este stub es un s\'imbolo fuerte.
          Con 1, este stub es un s\'imbolo debil. */
__attribute__((weak))
#endif
#if 1
unsigned int MCD(int NUM,int DEN){
 return 2;
}
#endif

void Fraccion::simplificar(){
 unsigned int mcd = MCD(N,D);
 N /= mcd; /**  N = N / mcd */
 D /= mcd; /**  D = D / mcd */
}

#if 1 //2021.10.05
std::string Fraccion::to_string(){
 char str[128];
 std::string result="";
#if 0 //2021.10.14
 char sgn_num,sgn_den;
 sgn_num = (n>=0)?'+':'-';
 sgn_den = (d>=0)?'+':'-';
 if (sgn_num==sgn_den) {
#else
 if (signo()=='+') {
#endif // 0
   sprintf(str,"\\frac{%u}{%u}",N,D);
 }else{
   sprintf(str,"{-}\\frac{%u}{%u}",N,D);
 }
 result = std::string(str);
 return result;
}
#endif

#if 1 //2021.10.14
/** '+' Si la Fracci\'on es > 0.
    '-' Si la Fracci\'on es < 0.
 */
char Fraccion::signo()
{
 char sgn_num,sgn_den;
 sgn_num = (n>=0)?'+':'-';
 sgn_den = (d>=0)?'+':'-';
 if (sgn_num==sgn_den) {
   return '+';
 }
 return '-';
}
#endif
