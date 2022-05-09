#include "VectorCont.h"
/**Inicializamos VectorCont::size en alcance de archivo*/
short VectorCont::size = 0;

void VectorCont::add(int valor){
 int_vec.push_back(valor);
 size++;
}

