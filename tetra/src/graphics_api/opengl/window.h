#ifndef TETRAHEDRON_TETRA_GRAPHICS_API_OPENGL_WINDOW_H
#define TETRAHEDRON_TETRA_GRAPHICS_API_OPENGL_WINDOW_H

#include "graphics_api/opengl/opengl.h"

namespace tetra::window {
using OpenGL = tetra::graphics::api::OpenGL;
class OpenGLWindow : public Window<OpenGL> {
public:
  OpenGLWindow(const Config& config);

private:
    GLFWwindow* m_window;
};
} // namespace tetra::window

#endif