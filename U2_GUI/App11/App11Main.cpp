/***************************************************************
 * Name:      App11Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2022-03-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "App11Main.h"
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
#if 1
    wxMessageBox(_T("¡Hola Mundo Unicode, para escribir en español!"),
    _T("Información"), wxOK | wxICON_INFORMATION, this);
    wxMessageBox(_T("¡Viva México!"),
    _T("Información"), wxOK | wxICON_INFORMATION, this);
#else
    wxMessageBox("Hola Mundo Unicode, para escribir en español!",
    _T("Información"), wxOK | wxICON_INFORMATION, this);
#endif // 0
}
