/***************************************************************
 * Name:      Unidad02Main.h
 * Purpose:   Defines Application Frame
 * Author:    LMC ()
 * Created:   2022-03-08
 * Copyright: LMC ()
 * License:
 * REF.
 **************************************************************/

#ifndef UNIDAD02MAIN_H
#define UNIDAD02MAIN_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include "Unidad02App.h"

class App11AppFrame: public wxFrame {
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

#endif // UNIDAD02MAIN_H
