#ifndef _CDUMMY_H_
#define _CDUMMY_H_
/**Ejemplo de una clase sin secciones privadas */
struct CDummy {
static int dummy_int; /** variable de estructura/clase */
  int intDI;          /** variable De Instancia */
static void dummy_func();
CDummy();             /**Constructor por defecto*/
};
#endif
