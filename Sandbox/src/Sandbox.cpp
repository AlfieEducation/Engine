#define _SCL_SECURE_NO_WARNINGS

#include "Engine.h"

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		EG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Engine::Event& event) override
	{
		EG_TRACE("{0}", event);
	}
};

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Engine::Application* Engine::CreateApplication() {
	return new Sandbox();
}