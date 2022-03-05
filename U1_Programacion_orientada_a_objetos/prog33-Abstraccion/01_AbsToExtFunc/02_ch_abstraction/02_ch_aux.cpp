#include <iostream>
#include <stdio.h>
//#include "../TimeSavingTechniques_util.h"
#include "../../prog33-Abstraccion_util.h"
char contacto[][256] = {
 "SIMPSON",
 "HOMER",
 "EVERGREEN AV.",
 "NEAR NUCLEAR PLANT",
 "SPRINGFIELD",
 "UNKNOWN",
 "123",
 "WILKINSON",
 "MALCOLM",
 "SUBS. AV.",
 "NEAR LOUISE'S WORK",
 "REESE MALCOLM AND DEWEY CITY",
 "UNKNOWN",
 "321"
};

int main(int argc,char *argv[]){
 int i;
 FILE *fp;
 print_ident_data(__FILE__,argv[0]);
// std::cout<<"Entries of array contacto: "
//          <<ARRAY_SIZE(contacto)
//          <<"\n";
 fp = fopen("contactos.raw","w");
#if 0
 for (i = 0; i < 14;i++) {
#else
 for (i = 0; i < ARRAY_SIZE(contacto);i++) {
#endif // 0
   fwrite(contacto[i],sizeof(char),255,fp);
 }
 fclose(fp);
 return 0;
}/*end main()*/
