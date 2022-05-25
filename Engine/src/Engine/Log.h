#pragma once

#include <memory>
#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"
#include "spdlog\fmt\ostr.h"

namespace Engine {
	class ENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define EG_CORE_ERROR(...)    ::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EG_CORE_WARN(...)     ::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EG_CORE_INFO(...)     ::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EG_CORE_TRACE(...)    ::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EG_CORE_CRITICAL(...)    ::Engine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define EG_ERROR(...)    ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define EG_WARN(...)     ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EG_INFO(...)     ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define EG_TRACE(...)    ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EG_CRITICAL(...)    ::Engine::Log::GetClientLogger()->critical(__VA_ARGS__)