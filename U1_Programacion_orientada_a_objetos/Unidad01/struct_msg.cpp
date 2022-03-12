/** struct_msg.cpp */
#include "struct_msg.h"

/**Sobrecarga del operador + para struct msg */
#ifdef CONFIG_SOBRECARGA_VERS_A
struct msg *struct_msg :: operator +(struct msg rhs)
{
 struct msg *result = new struct_msg;
 result->mensaje = mensaje +","+ rhs.mensaje;
 return result;
}
#endif // CONFIG_SOBRECARGA_VERS_A
#ifdef CONFIG_SOBRECARGA_VERS_B
struct msg *struct_msg :: operator +(struct msg rhs){
 std::vector<std::string> token;
 std::stringstream check(rhs.mensaje);
 std::string intermediate;
 struct msg *result = new struct_msg;
 result->mensaje = mensaje;
 // Tokenizing w.r.t. space ','
 while(getline(check, intermediate, ','))
 {
   token.push_back(intermediate);
 }
 for (unsigned int i=0;i<token.size();i++){
   if (!is_element(token[i])){
     result->mensaje = result->mensaje+","+token[i];
   }
 }
 update_tam();
 return result;
}

/** is_element
 * devuelve true si el string que recibe como argumento
 * ya forma parte de la lista de elementos separados por
 * comas del objeto impl\'icito.
 */
bool struct_msg :: is_element(std::string email)
{
 std::vector<std::string> vec_token;
 std::stringstream check(mensaje);
 std::string intermediate;
// struct msg *result = new struct_msg;
// result->mensaje = mensaje;
 // Tokenizing w.r.t. ','
 while(getline(check, intermediate, ','))
 {/**Aqu\'i agregamos un token (un correo) al vector vec_token */
   vec_token.push_back(intermediate);
 }/**Ahora en vec_token tenemos los correos*/
 for (unsigned int i=0;i<vec_token.size();i++){
   /** ?`es email igual al correo vec_token[i]? */
   if (email == vec_token[i]){
     return true;
   }
 }
 /**Si llegamos aqu\'i, significa que email no esta en la lista de
  * correos que tenemos en el atributo mensaje del objeto
  *impl\'icito.
  */
 return false;
}
#endif // CONFIG_SOBRECARGA_VERS_B

#ifdef CONFIG_SOBRECARGA_VERS_C
struct msg *struct_msg :: operator +(struct msg rhs){
 struct msg *result = new struct_msg;
 result->mensaje = mensaje;
 // Tokenizing rhs.mensaje w.r.t. ','
 std::vector<std::string> token = rhs.tokenizing_w_r_t(',');

 for (unsigned int i=0;i<token.size();i++){
   if (!is_element(token[i])){
     result->mensaje = result->mensaje+","+token[i];
   }
 }
 update_tam();
 return result;
}

/** is_element
 * devuelve true si el string que recibe como argumento
 * ya forma parte de la lista de elementos separados por
 * comas del objeto impl\'icito.
 */
bool struct_msg :: is_element(std::string email)
{
 // Tokenizing mensaje w.r.t. ','
 std::vector<std::string> vec_token = (*this).tokenizing_w_r_t(',');
 /**Ahora en vec_token tenemos los correos*/
 for (unsigned int i=0;i<vec_token.size();i++){
   /** ?`es email igual al correo vec_token[i]? */
   if (email == vec_token[i]){
     return true;
   }
 }
 /**Si llegamos aqu\'i, significa que email no esta en la lista de
  * correos que tenemos en el atributo mensaje del objeto
  *impl\'icito.
  */
 return false;
}
#endif // CONFIG_SOBRECARGA_VERS_C

/**
 * Coloca en tam la cantidad de correos que tenemos en la
 * lista de correos (en el string mensaje del objeto impl\'icito)
 */
void struct_msg :: update_tam()
{
 /**ESCRIBA SU CODIGO AQUI*/
 std::vector<std::string> vec_tok = tokenizing_w_r_t(',');
 tam = vec_tok.size();
}

std::vector<std::string> struct_msg :: tokenizing_w_r_t(char c)
{
 std::vector<std::string> vtok;
 std::stringstream check(mensaje);
 std::string intermediate;
 // Tokenizing w.r.t. c
 while(getline(check, intermediate, c))
 {/**Aqu\'i agregamos un token (un correo) al vector vtok */
   vtok.push_back(intermediate);
 }/**Ahora en vec_token tenemos los correos*/
 return vtok;
}

/**Sobrecarga del operador <<, std::cout << instanciaDstruct_msg */
std::ostream& operator <<(std::ostream& out,struct msg rhs)
{
 out << rhs.mensaje;
 return out;
}

