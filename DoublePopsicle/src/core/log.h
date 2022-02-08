#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace dp {

	class DP_API log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger> get_core_logger() { return spCoreLogger; };
		inline static std::shared_ptr<spdlog::logger> get_client_logger() { return spClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> spCoreLogger;
		static std::shared_ptr<spdlog::logger> spClientLogger;
	};
}

// core log macros
#define DP_CORE_ERROR(...)   ::dp::log::get_core_logger()->error(__VA_ARGS__)
#define DP_CORE_WARN(...)    ::dp::log::get_core_logger()->warn(__VA_ARGS__)
#define DP_CORE_INFO(...)    ::dp::log::get_core_logger()->info(__VA_ARGS__)
#define DP_CORE_TRACE(...)   ::dp::log::get_core_logger()->trace(__VA_ARGS__)
#define DP_CORE_FATAL(...)   ::dp::log::get_core_logger()->fatal(__VA_ARGS__)

// client
#define DP_ERROR(...)   ::dp::log::get_client_logger()->error(__VA_ARGS__)
#define DP_WARN(...)    ::dp::log::get_client_logger()->warn(__VA_ARGS__)
#define DP_INFO(...)    ::dp::log::get_client_logger()->info(__VA_ARGS__)
#define DP_TRACE(...)   ::dp::log::get_client_logger()->trace(__VA_ARGS__)
#define DP_FATAL(...)   ::dp::log::get_client_logger()->fatal(__VA_ARGS__)