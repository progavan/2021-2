#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <iostream>
#include <vector>

void display_gui(std::vector<std::string>& gifFile,
                 int x0,
                 int y0);
int create_gif(std::string gifFileName,
               std::string laTeXexp);

#endif // COMMON_H_INCLUDED
