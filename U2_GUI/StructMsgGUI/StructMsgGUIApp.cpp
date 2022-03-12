/***************************************************************
 * Name:      StructMsgGUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2022-03-08
 * Copyright:  ()
 * License:
 **************************************************************/

#include "StructMsgGUIApp.h"

//(*AppHeaders
#include "StructMsgGUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(StructMsgGUIApp);

bool StructMsgGUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	StructMsgGUIFrame* Frame = new StructMsgGUIFrame(0);
#if 1//LMC 2022.03.09
    	Frame->SetSize(1200,300);
#endif
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
