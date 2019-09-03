#pragma once
#include "Hazel/Core.h"

namespace Hazel
{
	class HAZEL_API Input
	{
	public : 
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode);}
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float,float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected : 
		virtual inline bool IsKeyPressedImpl(int keycode) = 0;
		virtual inline bool IsMouseButtonPressedImpl(int button) = 0 ;
		virtual inline std::pair<float,float> GetMousePositionImpl() = 0 ;
		virtual inline float GetMouseXImpl() = 0;
		virtual inline float GetMouseYImpl() = 0;
	private :
		static Input * s_Instance;
	};
}