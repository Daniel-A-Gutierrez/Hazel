#include "hzpch.h"
#include "WindowsInput.h"
#include "Hazel/Application.h"
#include <GLFW/glfw3.h>
namespace Hazel
{
	Input * Input::s_Instance = new WindowsInput();

	inline bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	inline bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton (window, button);
		return state == GLFW_PRESS; // a general macro for 1

	}
	inline float WindowsInput::GetMouseXImpl()
	{
		return GetMousePositionImpl().first;
	}
	inline float WindowsInput::GetMouseYImpl()
	{
		return GetMousePositionImpl().second;
	}
	inline std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return { (float)x, (float)y };
	}
}