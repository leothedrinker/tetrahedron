#include "graphics_api/opengl/opengl.h"
#include "ttpch.h"

namespace tetra::graphics::api {
template <> bool GraphicsAPIWrapper<OpenGL>::s_initialized = false;
bool OpenGL::init() {
  TT_TETRA_INFO("Initializing OpenGL...");
  return glfwInit();
}

} // namespace tetra::graphics::api