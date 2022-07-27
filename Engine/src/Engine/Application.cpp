#include "egpch.h"

#include "Application.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Log.h"

#include "glad/glad.h"

#include "Input.h"

namespace Engine
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		EG_CORE_ASSERT(!s_Instance, "Application is already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		unsigned int id;
		glGenVertexArrays(1, &id);
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		// EG_CORE_TRACE("({0})", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
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

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			auto [x, y] = Input::GetMousePosition();
			EG_CORE_TRACE("{0}, {1}", x, y);

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
