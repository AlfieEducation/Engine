#define _SCL_SECURE_NO_WARNINGS

#include "Engine.h"

#include "imgui/imgui.h"

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Engine::Input::IsKeyPressed(EG_KEY_TAB)) {
			EG_TRACE("Tab key is pressed");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Engine::Event& event) override
	{
		if (event.GetEventType() == Engine::EventType::KeyPressed) {
			Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&)event;
			EG_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		//PushOverlay(new Engine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Engine::Application* Engine::CreateApplication() {
	return new Sandbox();
}