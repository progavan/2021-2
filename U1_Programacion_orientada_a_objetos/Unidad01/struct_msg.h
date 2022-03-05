#ifndef STRUCT_MSG_H_INCLUDED
#define STRUCT_MSG_H_INCLUDED
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
typedef
struct msg {
 std::string mensaje;/**lista de correos separados por comas*/
 bool is_element(std::string);
 unsigned short tam;          /**Cantidad de correos en la lista*/
 struct msg *operator +(struct msg rhs);
 void update_tam();  /**actualiza el valor de tam*/
 std::vector<std::string> tokenizing_w_r_t(char c);/**Op Abstraction*/
friend std::ostream& operator <<(std::ostream& out,struct msg rhs);
} struct_msg;

#endif // STRUCT_MSG_H_INCLUDED
