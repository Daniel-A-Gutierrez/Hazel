#include "hzpch.h"
#include "Application.h"
#include "Hazel/Log.h"
#include "Events/Event.h"
#include "Input.h"
#include <glad/glad.h>

namespace Hazel
{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application * Application::s_Instance = nullptr;
	Application::Application()
	{
		HZ_CORE_ASSERT(!s_instance, "Application Already Exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		layer->OnAttach();
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		layer->OnAttach();
		m_LayerStack.PushOverlay(layer);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			auto[x, y] = Input::GetMousePosition();
			//HZ_CORE_TRACE("{0} , {1}", x, y);

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::OnEvent(Event & e)
	{
		HZ_TRACE("{0}", e);
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin() ; )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

}