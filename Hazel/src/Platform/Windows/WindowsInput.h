#pragma once
#include "Hazel/Input.h"

namespace Hazel
{
	class WindowsInput : public Input
	{
	protected:
		virtual inline bool IsKeyPressedImpl(int keycode) override;
		virtual inline bool IsMouseButtonPressedImpl(int button) override;
		virtual inline float GetMouseXImpl() override;
		virtual inline float GetMouseYImpl() override;
		virtual inline std::pair<float,float> GetMousePositionImpl() override;
	};
}