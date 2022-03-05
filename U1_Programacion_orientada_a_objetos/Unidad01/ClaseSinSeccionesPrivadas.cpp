/** ClaseSinSeccionesPrivadas.cpp*/
#include "struct_msg.h"
#include "Unidad01_util.h"

#ifdef CONFIG_CLASES_SIN_SECCIONES_PRIVADAS
#if 0
int main(int argc,char *argv[])
{
 struct msg m1,m2;
 struct msg *m3;
 struct msg m4;

 m1.mensaje = "jucag1805@hotmail.com";
 m2.mensaje = "diego.gj0902@gmail.com";

 m3 = m1 + m2;
 print_ident_data(__FILE__,argv[0]);
 m1.update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails m1: "
          <<m1.tam<<"\n\n";
 m2.update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails m2: "
          <<m2.tam<<"\n\n";
 std::cout << std::endl;
 std::cout << *m3 << std::endl;
 m3->update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails *m3: "
          <<m3->tam<<"\n\n";
 m4.mensaje = "gomezemmanuel58@gmail.com,\
juanpablo.jimenezleanos.10@gmail.com,felipelicea2@gmail.com";
 m3 = *m3 + m4;
 std::cout << *m3 << std::endl;
 m3->update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails: "
          <<m3->tam<<"\n\n";
 m4.mensaje = "alexis_lirag12@hotmail.com,\
ilopezs1701@alumno.ipn.mx,cmoralesv2000@alumno.ipn.mx,\
bryanalexanderph@gmail.com,edgar07quijano@gmail.com";
 m3 = *m3 + m4;
 std::cout << *m3 << std::endl;
 m3->update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails *m3: "
          <<m3->tam<<"\n\n";

 m4.mensaje = "418alma.rt@gmail.com,kalebgal@gmail.com,\
adrianhalo117@hotmail.com,mayocara32@gmail.com";
 m3 = *m3 + m4;
 std::cout << *m3 << std::endl;
 m3->update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails *m3: "
          <<m3->tam<<"\n";

 return 0;
}/*end main()*/
#else
int main(int argc,char *argv[])
{
 struct msg m1,m2;
 struct msg *m3;
 struct msg m4;
 print_ident_data(__FILE__,argv[0]);

 m1.mensaje = "jucag1805@hotmail.com";
 m2.mensaje = "diego.gj0902@gmail.com";

 m3 = m1 + m2;

 m4.mensaje = "gomezemmanuel58@gmail.com,\
juanpablo.jimenezleanos.10@gmail.com,jucag1805@hotmail.com,\
felipelicea2@gmail.com";

 std::cout << std::endl
           << "Lista de emails *m3: " << std::endl;
 std::cout << std::endl;
 std::cout << *m3 << std::endl;
 m3->update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails *m3: "
          <<m3->tam<<"\n\n";
 std::cout << std::endl
           << "Lista de emails m4: " << std::endl;
 std::cout << m4 << std::endl;
 m4.update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails m4: "
          <<m4.tam<<"\n\n";
 m3 = *m3 + m4;
 std::cout << "Despu\\'es de asignar m3 = *m3 + m4:" << std::endl
           << "Lista de emails *m3: " << std::endl;
 std::cout << *m3 << std::endl;
 m3->update_tam();
 std::cout<<"\nCantidad de emails en la lista de emails *m3: "
          <<m3->tam<<"\n\n";

 return 0;
}/*end main()*/
#endif // 0
#endif // CLASES_SIN_SECCIONES_PRIVADAS
