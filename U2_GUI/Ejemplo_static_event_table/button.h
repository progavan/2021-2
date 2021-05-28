#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <wx/wx.h>
class MyButton : public wxFrame
{
public:
    MyButton(const wxString& title);
    void OnQuit(wxCommandEvent& event);
private:
    DECLARE_EVENT_TABLE()
};
#endif // BUTTON_H_INCLUDED
