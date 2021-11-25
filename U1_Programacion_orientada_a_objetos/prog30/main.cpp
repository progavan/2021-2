#include <iostream>
using namespace std;
class ClaseA{
public:
  int atributo_x;
public:
  ClaseA(int x = 1):atributo_x(x){ }
  ClaseA(int a,int b):atributo_x(a+b){ }
  int metodo_x(){
    return atributo_x * 10;
  }
  int metodo_y(){
    return atributo_x + 100;
  }
};/* end ClaseA */

class ClaseB : public ClaseA {
public:
  int atributo_x;
public:
  ClaseB(int x = 2):atributo_x(x){ }
  int metodo_x(){
    //return atributo_x * -10;
    return ClaseA::atributo_x * -10;
  }
  int metodo_z(){   //  1           + 3 = 4
    atributo_x = ClaseA::atributo_x + 3;
    return ClaseA::metodo_x() + atributo_x;
  }        //    10           + 4 = 14
};/*end ClaseB*/

#ifdef CLASEA_Y_CLASEB
int main()
{
 cout << "ClaseA, ClaseB, p.497" << endl;
 ClaseB objClaseB;
 cout<<objClaseB.atributo_x<<endl;// 2
 cout<<objClaseB.metodo_y()<<endl;// 101
 cout<<objClaseB.metodo_x()<<endl;// -20,-10
 cout<<objClaseB.metodo_z()<<endl;// 14
 //ClaseB oCB(10,20);//Error, los
                     //constructores no se
                     //heredan
 return 0;
}
#endif // CLASEA_Y_CLASEB

/*
class A{ };
class B : public A{ };
class C : public B{ };
*/




