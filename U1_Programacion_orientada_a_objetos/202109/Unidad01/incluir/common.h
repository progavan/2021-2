#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <iostream>
#include <vector>
extern std::vector<std::string> gifFile;
void display_gui(std::vector<std::string>& gifFile,
                 int x0,
                 int y0);
int create_gif(std::string gifFileName,
               std::string laTeXexp);

class Util_push {
static unsigned int num_d_image;
public:
static void push(std::string laTeXexp);
};/*end class Util_push*/
#endif // COMMON_H_INCLUDED
