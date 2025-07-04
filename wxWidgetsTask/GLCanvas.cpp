#include "GLCanvas.h"
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

wxBEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
    EVT_PAINT(GLCanvas::OnPaint)
    EVT_SIZE(GLCanvas::OnSize)
    EVT_MOTION(GLCanvas::OnMouseMove)
    EVT_LEFT_DOWN(GLCanvas::OnMouseClick)
    EVT_LEAVE_WINDOW(GLCanvas::OnMouseLeave)
wxEND_EVENT_TABLE()

GLCanvas::GLCanvas(wxWindow* parent, wxWindowID id, const int* attribList)
    : wxGLCanvas(parent, id, attribList, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE),
      m_glContext(nullptr), m_initialized(false), m_rotation(0.0f), 
      m_showTriangle(true), m_buttonHovered(false), m_buttonSize(50, 50) {
    
    m_glContext = new wxGLContext(this);
    
    m_buttonPos = wxPoint(GetSize().GetWidth() - 60, 10);
    
    m_buttonIcon = wxBitmap(32, 32);
    wxMemoryDC dc(m_buttonIcon);
    dc.SetBackground(*wxRED_BRUSH);
    dc.Clear();
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.SetPen(*wxBLACK_PEN);
    dc.DrawCircle(16, 16, 12);
    dc.SelectObject(wxNullBitmap);
}

GLCanvas::~GLCanvas() {
    if (m_glContext) {
        delete m_glContext;
    }
}

void GLCanvas::InitGL() {
    if (m_initialized) return;
    
    SetCurrent(*m_glContext);
    
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    m_initialized = true;
}

void GLCanvas::RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glRotatef(m_rotation, 0.0f, 0.0f, 1.0f);
    
    if (m_showTriangle) {
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.5f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.5f);
        glEnd();
    }
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(0.3f * cos(angle), 0.3f * sin(angle));
    }
    glEnd();
    
    glFlush();
}

void GLCanvas::RenderOverlayButton() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, GetSize().GetWidth(), GetSize().GetHeight(), 0);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glEnable(GL_TEXTURE_2D);
    glColor3f(m_buttonHovered ? 0.8f : 1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(m_buttonPos.x, m_buttonPos.y);
    glVertex2f(m_buttonPos.x + m_buttonSize.GetWidth(), m_buttonPos.y);
    glVertex2f(m_buttonPos.x + m_buttonSize.GetWidth(), m_buttonPos.y + m_buttonSize.GetHeight());
    glVertex2f(m_buttonPos.x, m_buttonPos.y + m_buttonSize.GetHeight());
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(m_buttonPos.x, m_buttonPos.y);
    glVertex2f(m_buttonPos.x + m_buttonSize.GetWidth(), m_buttonPos.y);
    glVertex2f(m_buttonPos.x + m_buttonSize.GetWidth(), m_buttonPos.y + m_buttonSize.GetHeight());
    glVertex2f(m_buttonPos.x, m_buttonPos.y + m_buttonSize.GetHeight());
    glEnd();
    
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

bool GLCanvas::IsPointInButton(const wxPoint& point) {
    return point.x >= m_buttonPos.x && point.x <= m_buttonPos.x + m_buttonSize.GetWidth() &&
           point.y >= m_buttonPos.y && point.y <= m_buttonPos.y + m_buttonSize.GetHeight();
}

void GLCanvas::OnPaint(wxPaintEvent& event) {
    if (!IsShown()) return;
    
    wxPaintDC dc(this);
    
    if (!m_initialized) {
        InitGL();
    }
    
    SetCurrent(*m_glContext);
    RenderScene();
    RenderOverlayButton();
    
    SwapBuffers();
}

void GLCanvas::OnSize(wxSizeEvent& event) {
    if (m_glContext && IsShown()) {
        SetCurrent(*m_glContext);
        glViewport(0, 0, event.GetSize().GetWidth(), event.GetSize().GetHeight());
        
        m_buttonPos = wxPoint(event.GetSize().GetWidth() - 60, 10);
    }
    event.Skip();
}

void GLCanvas::OnMouseMove(wxMouseEvent& event) {
    bool wasHovered = m_buttonHovered;
    m_buttonHovered = IsPointInButton(event.GetPosition());
    
    if (wasHovered != m_buttonHovered) {
        Refresh();
    }
    
    event.Skip();
}

void GLCanvas::OnMouseClick(wxMouseEvent& event) {
    if (IsPointInButton(event.GetPosition())) {
        wxCommandEvent evt(wxEVT_BUTTON, wxID_ANY);
        evt.SetEventObject(this);
        GetParent()->GetEventHandler()->ProcessEvent(evt);
    }
    event.Skip();
}

void GLCanvas::OnMouseLeave(wxMouseEvent& event) {
    if (m_buttonHovered) {
        m_buttonHovered = false;
        Refresh();
    }
    event.Skip();
} 