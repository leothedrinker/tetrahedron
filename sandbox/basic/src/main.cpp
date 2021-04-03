#include "tetra.h"

int main() {
  tetra::log::Logger::initialize();
  tetra::window::Config conf{800, 600, "sandbox window"};
  auto app = tetra::application::Application<tetra::graphics::api::OpenGL>::createInstance("sandbox", conf);

}