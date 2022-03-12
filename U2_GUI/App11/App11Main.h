/***************************************************************
 * Name:      App11Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2022-03-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef APP11MAIN_H
#define APP11MAIN_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/button.h>

#include "App11App.h"

class App11Frame: public wxFrame {
    public:
        App11Frame(wxFrame *frame, const wxString& title);
        ~App11Frame();
    private:
        static const long idBtnClickMe;
        wxBoxSizer* m_boxSizerMain;
        wxButton* m_btnClickMe;
        void OnClickMe(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // APP11MAIN_H
