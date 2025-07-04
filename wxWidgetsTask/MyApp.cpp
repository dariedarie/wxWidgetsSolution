#include "MyApp.h"
#include "MainFrame.h"

bool MyApp::OnInit() {
    if (!wxApp::OnInit()) return false;
    
    MainFrame* frame = new MainFrame();
    frame->Show();
    
    return true;
}

wxIMPLEMENT_APP(MyApp); 