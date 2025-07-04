#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/frame.h>

class GLCanvas;
class ControlPanel;

class MainFrame : public wxFrame {
private:
    GLCanvas* m_canvas;
    ControlPanel* m_controlPanel;
    bool m_controlPanelVisible;
    
    void OnOverlayButtonClicked();
    void ToggleControlPanel();
    
public:
    MainFrame();
};

#endif 