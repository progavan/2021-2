/***************************************************************
 * Name:      StructMsgGUIMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2022-03-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef STRUCTMSGGUIMAIN_H
#define STRUCTMSGGUIMAIN_H

//(*Headers(StructMsgGUIFrame)
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class StructMsgGUIFrame: public wxFrame
{
    public:

        StructMsgGUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~StructMsgGUIFrame();

    private:

        //(*Handlers(StructMsgGUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnFileOpen(wxCommandEvent& event);
        //*)

        //(*Identifiers(StructMsgGUIFrame)
        static const long ID_TEXTCTRL_NOTEPAD;
        static const long idFileOpen;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(StructMsgGUIFrame)
        wxFileDialog* NotePadFileDialog;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlNotePad;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // STRUCTMSGGUIMAIN_H
