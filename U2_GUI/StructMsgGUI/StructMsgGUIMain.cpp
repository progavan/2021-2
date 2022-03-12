/***************************************************************
 * Name:      StructMsgGUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2022-03-08
 * Copyright:  ()
 * License:
 **************************************************************/

#include "StructMsgGUIMain.h"
#include <wx/msgdlg.h>
#include <wx/textfile.h>
#include <iostream>

//(*InternalHeaders(StructMsgGUIFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(StructMsgGUIFrame)
const long StructMsgGUIFrame::ID_TEXTCTRL_NOTEPAD = wxNewId();
const long StructMsgGUIFrame::idFileOpen = wxNewId();
const long StructMsgGUIFrame::ID_MENUITEM1 = wxNewId();
const long StructMsgGUIFrame::idMenuAbout = wxNewId();
const long StructMsgGUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(StructMsgGUIFrame,wxFrame)
    //(*EventTable(StructMsgGUIFrame)
    //*)
END_EVENT_TABLE()

StructMsgGUIFrame::StructMsgGUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(StructMsgGUIFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Emails list accumulator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    TextCtrlNotePad = new wxTextCtrl(this, ID_TEXTCTRL_NOTEPAD, wxEmptyString, wxPoint(128,144), wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL_NOTEPAD"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idFileOpen, _("&Open\tCtrl+O"), _("Abre un archivo de texto."), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    NotePadFileDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.txt"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    Connect(idFileOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&StructMsgGUIFrame::OnFileOpen);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&StructMsgGUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&StructMsgGUIFrame::OnAbout);
    //*)
}

StructMsgGUIFrame::~StructMsgGUIFrame()
{
    //(*Destroy(StructMsgGUIFrame)
    //*)
}

void StructMsgGUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void StructMsgGUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void StructMsgGUIFrame::OnFileOpen(wxCommandEvent& event)
{
 int result;
 wxTextFile textFile;
 wxString fileContent;

 result = NotePadFileDialog->ShowModal();
 if (result == wxID_OK) {
//   std::cout<<"result == wxID_OK was true!\n";
   if (textFile.Open(NotePadFileDialog->GetPath())) {
//     std::cout<<"textFile.Open(NotePadFileDialog->GetPath()) "
//              <<"was true!\n";
//     std::cout<<"textFile.GetLineCount() returns "
//              <<textFile.GetLineCount()<<"\n";
     for (size_t i = 0; i < textFile.GetLineCount(); i++) {
       fileContent << textFile.GetLine(i) << _T("\r\n");
//       std::cout<<fileContent<<"\n";
     }
     textFile.Close();
#if 0//LMC 2022.03.09
     TextCtrlNotePad->SetLabel(fileContent);
#else
     TextCtrlNotePad->SetValue(fileContent);
#endif // 0
   }
 }
}
