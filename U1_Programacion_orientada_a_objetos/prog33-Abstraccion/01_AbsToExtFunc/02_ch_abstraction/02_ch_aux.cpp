#include <stdio.h>
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

int main(){
 int i;
 FILE *fp;
 fp = fopen("contactos.raw","w");
 for (i = 0; i < 14;i++) {
   fwrite(contacto[i],sizeof(char),255,fp);
 }
 fclose(fp);
 return 0;
}/*end main()*/
