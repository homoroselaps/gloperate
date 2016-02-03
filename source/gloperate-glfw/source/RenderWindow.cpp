
#include <gloperate-glfw/RenderWindow.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <gloperate/viewer/input.h>
#include <gloperate/viewer/DemoRenderer.h>

#include <gloperate-glfw/WindowEvent.h>


using namespace gloperate;


namespace gloperate_glfw
{


/**
*  @brief
*    Convert GLFW mouse button into gloperate mouse button
*/
static gloperate::MouseButton fromGLFWMouseButton(int button)
{
    switch (button) 
    {
        case GLFW_MOUSE_BUTTON_1: return MouseButton1;
        case GLFW_MOUSE_BUTTON_2: return MouseButton2;
        case GLFW_MOUSE_BUTTON_3: return MouseButton3;
        case GLFW_MOUSE_BUTTON_4: return MouseButton4;
        case GLFW_MOUSE_BUTTON_5: return MouseButton5;
        case GLFW_MOUSE_BUTTON_6: return MouseButton6;
        case GLFW_MOUSE_BUTTON_7: return MouseButton7;
        case GLFW_MOUSE_BUTTON_8: return MouseButton8;
        default:                  return NoMouseButton;
    }
}

/**
*  @brief
*    Convert GLFW key code into gloperate key code
*/
static gloperate::Key fromGLFWKeyCode(int key)
{
    // We are using the same key code table as GLFW
    return static_cast<gloperate::Key>(key);
}


RenderWindow::RenderWindow()
: m_renderHandler(new gloperate::DemoRenderer)
{
}

RenderWindow::~RenderWindow()
{
    delete m_renderHandler;
}

void RenderWindow::onContextInit()
{
    m_renderHandler->onContextInit();
}

void RenderWindow::onContextDeinit()
{
    m_renderHandler->onContextDeinit();
}

void RenderWindow::onIdle()
{
}

void RenderWindow::onResize(ResizeEvent &)
{
}

void RenderWindow::onFramebufferResize(ResizeEvent & event)
{
    m_renderHandler->onResize(
        event.width()
      , event.height()
    );
}

void RenderWindow::onMove(MoveEvent &)
{
}

void RenderWindow::onPaint(PaintEvent &)
{
    m_renderHandler->onRender();
}

void RenderWindow::onKeyPress(KeyEvent & event)
{
    m_renderHandler->onKeyPress(
        fromGLFWKeyCode(event.key())
    );
}

void RenderWindow::onKeyRelease(KeyEvent & event)
{
    m_renderHandler->onKeyRelease(
        fromGLFWKeyCode(event.key())
    );
}

void RenderWindow::onMousePress(MouseEvent & event)
{
    m_renderHandler->onMousePress(
        fromGLFWMouseButton(event.button())
      , event.x()
      , event.y()
    );
}

void RenderWindow::onMouseRelease(MouseEvent & event)
{
    m_renderHandler->onMouseRelease(
        fromGLFWMouseButton(event.button())
      , event.x()
      , event.y()
    );
}

void RenderWindow::onMouseMove(MouseEvent & event)
{
    m_renderHandler->onMouseMove(
        event.x()
      , event.y()
    );
}

void RenderWindow::onMouseEnter(MouseEnterEvent &)
{
}

void RenderWindow::onMouseLeave(MouseLeaveEvent &)
{
}

void RenderWindow::onScroll(ScrollEvent &)
{
}

void RenderWindow::onFocus(FocusEvent &)
{
}

void RenderWindow::onIconify(IconifyEvent &)
{
}

void RenderWindow::onTimer(TimerEvent &)
{
}


} // namespace gloperate_glfw