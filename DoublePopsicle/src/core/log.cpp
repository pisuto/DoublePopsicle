#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace dp {

	std::shared_ptr<spdlog::logger> log::spCoreLogger;
	std::shared_ptr<spdlog::logger> log::spClientLogger;

	void log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		spCoreLogger = spdlog::stdout_color_mt("POPSICLE");
		spCoreLogger->set_level(spdlog::level::trace);

		spClientLogger = spdlog::stdout_color_mt("APP");
		spClientLogger->set_level(spdlog::level::trace);

	}
}
