// virtual.cpp - M\'etodos virtuales
// y no virtuales
#include <iostream>
using namespace std;
#ifdef METODOS_VIRTUALES_Y_NO_VIRTUALES
class CB {
public:
 virtual ~CB(){ }
 virtual void mVirtual1(); //virtual method
 void mNoVirtual(); //non-virtual method
};

void CB::mVirtual1(){
 cout << "m\\'etodo virtual 1 en CB\n";
}
void CB::mNoVirtual(){
 cout << "m\\'etodo no virtual en CB\n";
}

class CD1 : public CB {
public:
 void mVirtual1(); //virtual method
 virtual void mVirtual2();//virtual method
 void mNoVirtual();
};

void CD1::mVirtual1(){
 cout << "m\\'etodo virtual 1 en CD1\n";
}
void CD1::mVirtual2(){
 cout << "m\\'etodo virtual 2 en CD1\n";
}
void CD1::mNoVirtual(){
 cout << "m\\'etodo no virtual en CD1\n";
}

class CD2 : public CD1{
public:
 void mVirtual1(); //virtual method
 void mVirtual2(); //virtual method
 void mNoVirtual();//non-virtual method
};

void CD2::mVirtual1(){
 cout << "m\\'etodo virtual 1 en CD2\n";
}
void CD2::mVirtual2(){
 cout << "m\\'etodo virtual 2 en CD2\n";
}
void CD2::mNoVirtual(){
 cout << "m\\'etodo no virtual en CD2\n";
}

void fx(CB *p){//funci\'on externa
 p->mVirtual1();
 //...
}

int main(){
 CB *p1CB = new CD1;  //pointer a CB que apunta a CD1
 CD1 *p1CD1 = new CD2;//pointer a CD1 que apunta a CD2
 CB *p2CB = new CD2;  //pointer a CB que apunta a CD2
 //Llamadas a los m\'etodos
 p1CB->mVirtual1();      //llama a CD1::mvirtual1
 p1CB->mNoVirtual();     //llama a CB::mNoVirtual
 p1CB->CB::mVirtual1();  //llama a CB::mVirtual1
 p1CD1->mVirtual2();     //llama a CD2::mVirtual2
 p1CD1->mNoVirtual();    //llama a CD1::mNoVirtual
 p1CD1->CD1::mVirtual2();//llama a CD1::mVirtual2
 fx(p2CB);               //llama a CD2::mVirtual1
 delete p1CB;
 delete p1CD1;
 delete p2CB;
 return 0;
}/*end main()*/
#endif // METODOS_VIRTUALES_Y_NO_VIRTUALES


