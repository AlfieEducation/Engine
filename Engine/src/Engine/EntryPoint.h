#pragma once

#ifdef EG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	EG_CORE_WARN("Core warn log example");
	EG_CORE_ERROR("Core error log example");
	EG_INFO("Common info log example");
	EG_CRITICAL("Common fatal log example");

	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}
#endif