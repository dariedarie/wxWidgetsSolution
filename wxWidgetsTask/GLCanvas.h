#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <wx/glcanvas.h>
#include <wx/bitmap.h>

class GLCanvas : public wxGLCanvas {
private:
    wxGLContext* m_glContext;
    bool m_initialized;
    float m_rotation;
    bool m_showTriangle;
    bool m_buttonHovered;
    wxPoint m_buttonPos;
    wxSize m_buttonSize;
    wxBitmap m_buttonIcon;
    
    void OnMouseMove(wxMouseEvent& event);
    void OnMouseClick(wxMouseEvent& event);
    void OnMouseLeave(wxMouseEvent& event);
    
    void InitGL();
    void RenderScene();
    void RenderOverlayButton();
    bool IsPointInButton(const wxPoint& point);
    
    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnEraseBackground(wxEraseEvent& event) {}
    
public:
    GLCanvas(wxWindow* parent, wxWindowID id = wxID_ANY, const int* attribList = nullptr);
    ~GLCanvas();
    
    void SetRotation(float rotation) { m_rotation = rotation; Refresh(); }
    void SetShowTriangle(bool show) { m_showTriangle = show; Refresh(); }
    float GetRotation() const { return m_rotation; }
    bool GetShowTriangle() const { return m_showTriangle; }
    
    wxDECLARE_EVENT_TABLE();
};

#endif 