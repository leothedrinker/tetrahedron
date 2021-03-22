#include "common/log/logger.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace tetra::log {
std::shared_ptr<spdlog::logger> Logger::s_tetra_logger;
std::shared_ptr<spdlog::logger> Logger::s_client_logger;

void Logger::initialize() {
  std::vector<spdlog::sink_ptr> log_sinks;
  log_sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  log_sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("tetra.log", true));

  log_sinks[0]->set_pattern("%^[%T] %n: %v%$");
  log_sinks[1]->set_pattern("[%T] [%l] %n: %v");

  s_tetra_logger = std::make_unique<spdlog::logger>("TETRA", begin(log_sinks), end(log_sinks));
  spdlog::register_logger(s_tetra_logger);
  s_tetra_logger->set_level(spdlog::level::trace);
  s_tetra_logger->flush_on(spdlog::level::trace);

  s_client_logger = std::make_shared<spdlog::logger>("CLIENT", begin(log_sinks), end(log_sinks));
  spdlog::register_logger(s_client_logger);
  s_client_logger->set_level(spdlog::level::trace);
  s_client_logger->flush_on(spdlog::level::trace);
}

spdlog::logger& Logger::get_tetra_logger() { return *s_tetra_logger; }
spdlog::logger& Logger::get_client_logger() { return *s_client_logger; }

} // namespace tetra::log
