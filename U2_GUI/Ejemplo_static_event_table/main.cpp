#include "main.h"
#include "button.h"
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyButton *button = new MyButton(wxT("Button"));
    button->Show(true);
    return true;
}
