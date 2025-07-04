#include "ControlPanel.h"
#include "GLCanvas.h"
#include <wx/sizer.h>
#include <wx/stattext.h>

ControlPanel::ControlPanel(wxWindow* parent, GLCanvas* canvas)
    : wxPanel(parent), m_canvas(canvas) {
    
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    
    wxStaticText* rotationLabel = new wxStaticText(this, wxID_ANY, "Rotation:");
    m_rotationSlider = new wxSlider(this, wxID_ANY, 0, 0, 360, 
                                   wxDefaultPosition, wxDefaultSize,
                                   wxSL_HORIZONTAL | wxSL_LABELS);
    
    m_triangleCheckBox = new wxCheckBox(this, wxID_ANY, "Show Triangle");
    m_triangleCheckBox->SetValue(true);
    
    sizer->Add(rotationLabel, 0, wxALL, 5);
    sizer->Add(m_rotationSlider, 0, wxEXPAND | wxALL, 5);
    sizer->Add(m_triangleCheckBox, 0, wxALL, 5);
    
    SetSizer(sizer);
    
    m_rotationSlider->Bind(wxEVT_SLIDER, &ControlPanel::OnRotationChanged, this);
    m_triangleCheckBox->Bind(wxEVT_CHECKBOX, &ControlPanel::OnTriangleToggled, this);
}

void ControlPanel::OnRotationChanged(wxCommandEvent& event) {
    if (m_canvas) {
        m_canvas->SetRotation(m_rotationSlider->GetValue());
    }
}

void ControlPanel::OnTriangleToggled(wxCommandEvent& event) {
    if (m_canvas) {
        m_canvas->SetShowTriangle(m_triangleCheckBox->GetValue());
    }
} 