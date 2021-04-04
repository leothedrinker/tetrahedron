
#include <type_traits>

#include "application/application.h"
#include "ttpch.h"

namespace tetra::application {
using namespace tetra;

template <typename GraphicsAPI>
Application<GraphicsAPI>::Application(const std::string& name, std::shared_ptr<window::Window<GraphicsAPI>> window)
    : m_name(name), m_window(window) {
  TT_TETRA_INFO("creating app {}", name);
}

template <typename GraphicsAPI> Application<GraphicsAPI>::~Application() { TT_TETRA_INFO("retiring app {}", m_name); }

template <typename GraphicsAPI>
std::shared_ptr<Application<GraphicsAPI>> Application<GraphicsAPI>::createInstance(const std::string& name,
                                                                                   const window::Config& config) {
  GraphicsAPI::init();
  auto app_window = std::make_shared<window::Window<GraphicsAPI>>(config);
  return std::make_shared<Application<GraphicsAPI>>(name, app_window);
}
} // namespace tetra::application