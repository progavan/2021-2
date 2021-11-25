//constructores-v.cpp
//programa que simula constructor virtual
#include <iostream>
using namespace std;
#ifdef CONSTRUCTORES_VIRTUALES
class CB {
private:
  int i;
public:
  // Constructor por defecto
  CB(){ cout << "constructor CB -- "; }
  virtual ~CB() { cout << "CB::~CB() -- "; }
  //...
  virtual CB *nuevo(){
    cout << "CB::nuevo() -- ";
    return new CB;
  }
  virtual CB *clonar(){
    cout << "CB::clonar() -- ";
    return new CB(*this);
  }
};/*end class CB*/

class CD : public CB{
private:
  double d;
public:
  // Constructor por defecto
  CD() { cout << "constructor CD -- \n"; }
  ~CD() { cout << "CD::~CD() -- "; }
  //...
  CD *nuevo() {
    cout << "CD::nuevo() -- ";
    return new CD;
  }
  CD *clonar() {
    cout << "CD::clonar() -- ";
    return new CD(*this);
  }
};/*end class CD*/

CB *crearObjeto(CB *p){
  return p->nuevo();
}

int main(){
  CB obj_cb, *cb = &obj_cb;
  CD obj_cd, *cd = &obj_cd;

  cout << "\ncrearObjeto(cb)\n";
  CB *p1 = crearObjeto(cb);// crea un objeto CB
  cout << "\ncrearObjeto(cd)\n";
  CB *p2 = crearObjeto(cd);// crea un objeto CD

  cout << "\np1->clonar()\n";
  CB *p3 = p1->clonar();
  cout << "\np2->clonar()\n";
  CB *p4 = p2->clonar();

  //...
  // Liberar memoria
  cout <<"\n\ndelete p1\n";
  delete p1;
  cout <<"\ndelete p2\n";
  delete p2;
  cout <<"\ndelete p3\n";
  delete p3;
  cout <<"\ndelete p4\n";
  delete p4;
  cout << "\n\nAl llegar al final de main()\n";

  return 0;
}/*end main()*/
#endif // CONSTRUCTORES_VIRTUALES


