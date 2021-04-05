#include <wx/wx.h>
#include <wx/image.h>
#include "Main.h"


class App: public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(App)

bool App::OnInit()
{
    wxInitAllImageHandlers();
    Main* main = new Main(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(main);
    main->Show();
    return true;
}
