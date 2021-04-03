#ifndef TETRAHEDRON_TETRA_WINDOW_WINDOW_H
#define TETRAHEDRON_TETRA_WINDOW_WINDOW_H

#include "ttpch.h"
#include "window/config.h"

namespace tetra::graphics::api {
  class OpenGL;
}

namespace tetra::window {

using namespace tetra;

template <typename Window> class WindowInterface {
public:
  explicit WindowInterface(const Config& config) : m_config(config) {
    TT_TETRA_INFO("creating window {}", config.title);
  };
  ~WindowInterface() = default;
  WindowInterface(const WindowInterface&) = delete;
  WindowInterface& operator=(const WindowInterface&) = delete;
  WindowInterface(WindowInterface&&) = default;
  WindowInterface& operator=(WindowInterface&&) = default;

protected:
  Config m_config;
};

template <typename GraphicsAPI> class Window : public WindowInterface<Window<GraphicsAPI>> {
public:
  explicit Window(const Config& config) : WindowInterface<Window<GraphicsAPI>>(config) {};
  ~Window() = default;
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  Window(Window&&) = default;
  Window& operator=(Window&&) = default;
};

template class Window<tetra::graphics::api::OpenGL>;

} // namespace tetra::window

#endif