#ifndef TETRAHEDRON_TETRA_COMMON_LOG_LOGGER_H
#define TETRAHEDRON_TETRA_COMMON_LOG_LOGGER_H

#include "spdlog/spdlog.h"
#include <memory>
#include <string>

namespace tetra::log {

class Logger {

public:
  static void initialize();
  static spdlog::logger& get_tetra_logger();
  static spdlog::logger& get_client_logger();

private:
  static std::shared_ptr<spdlog::logger> s_tetra_logger;
  static std::shared_ptr<spdlog::logger> s_client_logger;
};

} // namespace tetra::log

#define TT_TETRA_TRACE(...) ::tetra::log::Logger::get_tetra_logger().trace(__VA_ARGS__)
#define TT_TETRA_INFO(...) ::tetra::log::Logger::get_tetra_logger().info(__VA_ARGS__)
#define TT_TETRA_WARNING(...) ::tetra::log::Logger::get_tetra_logger().warning(__VA_ARGS__)
#define TT_TETRA_ERROR(...) ::tetra::log::Logger::get_tetra_logger().error(__VA_ARGS__)
#define TT_TETRA_FATAL(...) ::tetra::log::Logger::get_tetra_logger().fatal(__VA_ARGS__)

#define TT_TRACE(...) ::tetra::log::Logger::get_client_logger().trace(__VA_ARGS__)
#define TT_INFO(...) ::tetra::log::Logger::get_client_logger().info(__VA_ARGS__)
#define TT_WARNING(...) ::tetra::log::Logger::get_client_logger().warning(__VA_ARGS__)
#define TT_ERROR(...) ::tetra::log::Logger::get_client_logger().error(__VA_ARGS__)
#define TT_FATAL(...) ::tetra::log::Logger::get_client_logger().fatal(__VA_ARGS__)

#endif