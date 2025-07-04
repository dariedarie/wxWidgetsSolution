#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/checkbox.h>

class GLCanvas;

class ControlPanel : public wxPanel {
private:
    GLCanvas* m_canvas;
    wxSlider* m_rotationSlider;
    wxCheckBox* m_triangleCheckBox;
    
    void OnRotationChanged(wxCommandEvent& event);
    void OnTriangleToggled(wxCommandEvent& event);
    
public:
    ControlPanel(wxWindow* parent, GLCanvas* canvas);
};

#endif 