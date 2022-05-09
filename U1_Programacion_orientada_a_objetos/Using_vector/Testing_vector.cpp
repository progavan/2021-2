#include <iostream>
#include <vector>
#include <cassert> // <assert.h>
#define CONFIG_MAIN_MODULE
/**
 OPCION 1) Definir CONFIG_USING_INT_ARRAY_ARR y comentar
           la l\'inea #define CONFIG_USE_INCOMPLETE_ARRAY
 #define CONFIG_USING_INT_ARRAY_ARR
 //#define CONFIG_USE_INCOMPLETE_ARRAY
 OPCION 2) Comentar la l\'inea #define CONFIG_USING_INT_ARRAY_ARR
           y definir CONFIG_USE_INCOMPLETE_ARRAY
 //#define CONFIG_USING_INT_ARRAY_ARR
 #define CONFIG_USE_INCOMPLETE_ARRAY
 */
//#define CONFIG_USING_INT_ARRAY_ARR
#define CONFIG_USE_INCOMPLETE_ARRAY
#include "VectorCont.h"

using namespace std;
static char articulo[][128] = {
 "Ley federal del trabajo",
 "Ley federal de la educaci\\'on",
 "Ley federal de tierras y aguas"
};
#include "datos.cpp"
//gnome-terminal --maximize -t $TITLE -x
//short NyArr::N=3;
int NyArr::Arr[] = {2,4,6,8}; /**Para poder hacer esto, int NyArr::Arr[] debe ser static */
int main()
{
 std::vector<int> int_vec;
 VectorCont VC;
 int_vec.push_back(123);
 int_vec.push_back(3);
 int_vec.push_back(27);
 VC.add(123);
 VC.add(3);
 VC.add(27);
 //NyArr nyarr = {4,{2,4,6,8}};
 //Testing_vector.cpp:24:28: error: non-static initialization of a flexible array member
 //int myArr[] = {2,4,6,8};

 NyArr nyarr;
 nyarr.N=LENGTH(NyArr::Arr);
 //nyarr.Arr=myArr;

 for(size_t i=0;i<LENGTH(myArr);i++){
    nyarr.Arr[i]=myArr[i];
 }
 nyarr.N=LENGTH(myArr);

 cout << "Proyecto: Using_vector.cbp"
      << endl << endl;
 std::cout<<"Art\\'iculos m\\'as conocidos de \
la constituci\\'on mexicana:"<<std::endl;
 //short
 long unsigned int
#ifdef CONFIG_USING_INT_ARRAY_ARR
 tam_d_arr = LENGTH(arr);
 for(size_t i=0;i<tam_d_arr;i++)
   VC.add(arr[i]);
 //static_assert(LENGTH(articulo)==int_vec.size(),
 //"Debemos tener tantos art\\'iculos como elementos en el vector int_vec");
 static_assert(LENGTH(articulo)==LENGTH(arr),
 "Debemos tener tantos art\\'iculos como elementos en el vector int_vec");
 //assert(LENGTH(articulo)==int_vec.size());//(3==3)?continuar:detener;
#else
 tam_d_arr = nyarr.N;
 //p = new NyArr;

 //std::cout << "Cantidad de enteros: ";
 //std::cin >> p->N;

 for(size_t i=0;i<tam_d_arr;i++)
   VC.add(nyarr.Arr[i]);
 //static_assert(LENGTH(articulo)==int_vec.size(),
 //"Debemos tener tantos art\\'iculos como elementos en el vector int_vec");
#ifndef CONFIG_USE_INCOMPLETE_ARRAY
 static_assert(LENGTH(articulo)==LENGTH(nyarr.Arr),
 "Debemos tener tantos art\\'iculos como elementos en el arreglo int myArr[] \
(archivo VectorCont.h)");
#endif // CONFIG_USE_INCOMPLETE_ARRAY
 //assert(LENGTH(articulo)==int_vec.size());//(3==3)?continuar:detener;
#endif



 for(size_t i=0;i<int_vec.size();i++){
   std::cout<<"i="<<i<<" "
            <<int_vec[i]
            << " "
            <<articulo[i]
            <<std::endl;
 }
 int_vec.clear();
 std::cout<<"\n\nDespu\\'es de reutilizar el vector\n";
 int_vec.push_back(10);
 for(size_t i=0;i<int_vec.size();i++){
   std::cout<<int_vec[i]<<std::endl;
 }
 std::cout<<"\n\nEl m\\'etodo add() se utiliz\\'o "
          <<VectorCont::size<<" veces.\n";
 return 0;
}
