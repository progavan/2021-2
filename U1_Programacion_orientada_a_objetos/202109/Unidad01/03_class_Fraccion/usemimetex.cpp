/**usemimetex.cpp*/
#include <iostream>
#include <windows.h>
#include <stdio.h>
#define MIMETEX "mimetex.exe"
int create_gif(std::string gifFileName,std::string laTeXexp)
{
  char str[128];
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory(&si,sizeof(si));
  si.cb=sizeof(si);
  ZeroMemory(&pi,sizeof(pi));
  #if 0 //2021.10.14
  std::cout<<"gifFileName="<<gifFileName<<"\n";
  std::cout<<"laTeXexp="<<laTeXexp<<"\n";
  #endif // 1
  #if 0 //2021.10.14
  sprintf(str,"mimetex.exe -e %s \"%s\"",&gifFileName[0],
  #else
  sprintf(str,"mimetex.exe -e %s \"%s\"",gifFileName.c_str(),
  #endif // 0
          &laTeXexp[0]);
  #if 0 //2021.10.14
  printf("\n\nstr:%s\n\n",str);
  #endif // 1
  if(!CreateProcess(MIMETEX,str,0,0,0,0,0,0,&si,&pi)){
    /*Could not start process*/
    std::cerr<<"Could not start process in order to execute mimetex.exe :-( "<<std::endl;
    /** In case you see the message
        "Could not start process in order to execute mimetex.exe :-( ",
        change the field Execution working dir:
        to the location of the executable file mimetex.exe
        i.e., in CodeBlocks:
        Project->Properties
                 --> Build Targets
                 Execution working dir: .
        (or you could copy the file mimetex.exe to the
         location indicated by the field
         Execution working dir:
         in Project->Properties
                 --> Build Targets)*/
    return -1;
  }
  CloseHandle( pi.hThread );
  // wait for the child program to terminate
  WaitForSingleObject( pi.hProcess, INFINITE );
  return 0;
}/*end create_gif()*/

