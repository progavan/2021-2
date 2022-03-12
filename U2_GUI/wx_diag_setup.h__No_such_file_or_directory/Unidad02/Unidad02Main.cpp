/***************************************************************
 * Name:      Unidad02Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    LMC ()
 * Created:   2022-03-08
 * Copyright: LMC ()
 * License:
 **************************************************************/

#include "Unidad02Main.h"
const long App11Frame::idBtnClickMe = ::wxNewId();

BEGIN_EVENT_TABLE(App11Frame, wxFrame)
    EVT_BUTTON(idBtnClickMe, App11Frame::OnClickMe)
    EVT_CLOSE(App11Frame::OnClose)
END_EVENT_TABLE()

App11Frame::App11Frame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    m_boxSizerMain = new wxBoxSizer(wxHORIZONTAL);
    m_btnClickMe = new wxButton(this, idBtnClickMe, _T("Click Me!"),
                                wxDefaultPosition, wxDefaultSize, 0);
    m_boxSizerMain->Add(m_btnClickMe, 0, wxALL, 5);
    this->SetSizer(m_boxSizerMain);
    this->Layout();
}

App11Frame::~App11Frame() {
}

void App11Frame::OnClose(wxCloseEvent &event) {
    Destroy();
}

void App11Frame::OnClickMe(wxCommandEvent& event) {
    wxMessageBox(_T("Hello World!"), _T("Information"), wxOK | wxICON_INFORMATION, this);
}
