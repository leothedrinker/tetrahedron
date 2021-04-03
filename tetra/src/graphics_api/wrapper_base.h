#ifndef TETRAHEDRON_TETRA_GRAPHICS_API_WRAPPER_BASE_H
#define TETRAHEDRON_TETRA_GRAPHICS_API_WRAPPER_BASE_H

#include "window/config.h"
#include "window/window.hpp"

namespace tetra::graphics::api {
using namespace tetra;
template <typename GraphicsAPI> class GraphicsAPIWrapper {
public:
  static bool init() {
    if (!s_initialized) {
      s_initialized = true;
      return GraphicsAPI::init();
    }
    return true;
  }

protected:
  static bool s_initialized;
};

} // namespace tetra::graphics::api

#endif