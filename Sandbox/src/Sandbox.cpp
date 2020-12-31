#define _SCL_SECURE_NO_WARNINGS

#include "Engine.h"

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Engine::Application* Engine::CreateApplication() {
	return new Sandbox();
}