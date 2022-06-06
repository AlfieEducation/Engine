#include "egpch.h"

#include "Application.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Log.h"

#include "GLFW/glfw3.h"

namespace Engine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run() {
		/*WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			EG_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			EG_TRACE(e);
		}*/
		
		while (m_Running) {
			glClearColor(0, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}
