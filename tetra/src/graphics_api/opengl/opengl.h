#ifndef TETRAHEDRON_TETRA_GRAPHICS_API_OPENGL_OPENGL_H
#define TETRAHEDRON_TETRA_GRAPHICS_API_OPENGL_OPENGL_H

#include "graphics_api/wrapper_base.h"
#include <GLFW/glfw3.h>

namespace tetra::graphics::api {
using namespace tetra;
class OpenGL : public GraphicsAPIWrapper<OpenGL> {
public:
  static bool init();
};
} // namespace tetra::graphics::api

#endif