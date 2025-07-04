#include "MainFrame.h"
#include "GLCanvas.h"
#include "ControlPanel.h"
#include <wx/sizer.h>

MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "Interactive GL Canvas with Controls", 
              wxDefaultPosition, wxSize(800, 600)),
      m_controlPanelVisible(false) {
    
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    
    m_canvas = new GLCanvas(this, wxID_ANY, nullptr);
    mainSizer->Add(m_canvas, 1, wxEXPAND);
    
    m_controlPanel = new ControlPanel(this, m_canvas);
    m_controlPanel->Hide();
    mainSizer->Add(m_controlPanel, 0, wxEXPAND);
    
    SetSizer(mainSizer);
    
    Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { OnOverlayButtonClicked(); });
    
    Centre();
}

void MainFrame::OnOverlayButtonClicked() {
    ToggleControlPanel();
}

void MainFrame::ToggleControlPanel() {
    m_controlPanelVisible = !m_controlPanelVisible;
    
    if (m_controlPanelVisible) {
        m_controlPanel->Show();
    } else {
        m_controlPanel->Hide();
    }
    
    Layout();
    Refresh();
} 