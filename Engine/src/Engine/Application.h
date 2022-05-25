#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	//To be define in client
	Application* CreateApplication();
}
