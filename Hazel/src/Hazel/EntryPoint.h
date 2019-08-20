#pragma once
#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argvv)
{
	printf("Hazel Engine\n");

	Hazel::Log::Init();
	HZ_CORE_TRACE("core logger initialized");
	HZ_INFO("hi g");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif