#include "graphics_api/opengl/window.h"

namespace tetra::window {
    using namespace tetra;
    
    OpenGLWindow::OpenGLWindow(const Config& config) : Window<OpenGL>(config) {
        TT_TETRA_TRACE("creating glfw window {} {} {}", config.width, config.height, config.title);
        m_window = glfwCreateWindow(config.width, config.height, config.title.c_str(), NULL, NULL);
    }
    
}