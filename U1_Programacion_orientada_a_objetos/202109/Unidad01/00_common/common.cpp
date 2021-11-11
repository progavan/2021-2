#include <stdio.h>
#include <common.h>

std::vector<std::string> gifFile;
unsigned int Util::num_d_image = 0;

void Util::push(std::string laTeXexp)
{
 char str[128];
 std::string imgFileName;
 sprintf(str,"file%u.gif",num_d_image);
 imgFileName = std::string(str);
 create_gif(imgFileName,laTeXexp);
 gifFile.push_back(imgFileName);
 num_d_image++;
}

