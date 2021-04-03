#ifndef TETRAHEDRON_TETRA_APPLICATION_APPLICATION_H
#define TETRAHEDRON_TETRA_APPLICATION_APPLICATION_H

#include "ttpch.h"
#include "window/window.hpp"
#include "graphics_api/opengl/opengl.h"

namespace tetra::application {

using namespace tetra;

template <typename GraphicsAPI> class Application {

public:
  explicit Application(const std::string& name, std::shared_ptr<window::Window<GraphicsAPI>> window);
  ~Application();
  Application() = delete;
  Application(const Application&) = delete;
  Application(Application&&) = default;
  Application& operator=(Application&) = delete;
  Application& operator=(Application&&) = default;

  static std::shared_ptr<Application<GraphicsAPI>> createInstance(const std::string& name, const window::Config& config);

private:
  std::string m_name;
  std::shared_ptr<window::Window<GraphicsAPI>> m_window;
};

template class Application<graphics::api::OpenGL>;

} // namespace tetra::application

#endif