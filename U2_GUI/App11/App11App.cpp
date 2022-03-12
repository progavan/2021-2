/***************************************************************
 * Name:      App11App.cpp
 * Purpose:   Code for Application Class
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

#include "App11App.h"
#include "App11Main.h"

IMPLEMENT_APP(App11App);

bool App11App::OnInit() {
    App11Frame* frame = new App11Frame(0L, _("wxWidgets Application Template"));
    #ifdef __WXMSW__
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    #endif
    frame->Show();

    return true;
}
