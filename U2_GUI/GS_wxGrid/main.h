#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <wx/wx.h>
class wxGrid;

class GSwxGridApp : public wxApp
{
public:
 bool OnInit() wxOVERRIDE;
};

class GridFrame : public wxFrame
{
    wxGrid         *grid;
public:
    GridFrame();
    ~GridFrame();
#if wxUSE_LOG
    wxLog *m_logOld;
#endif // wxUSE_LOG
};
#endif // MAIN_H_INCLUDED
