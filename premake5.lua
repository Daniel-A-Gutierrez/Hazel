workspace "Hazel"
	architecture "x64"
	startproject "Sandbox"
 	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}




outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"
IncludeDir["glad"] = "Hazel/vendor/glad/include"
IncludeDir["ImGui"] = "Hazel/vendor/imgui"
IncludeDir["glm"] = "Hazel/vendor/glm"

include "Hazel/vendor/GLFW"
include "Hazel/vendor/glad"
include "Hazel/vendor/imgui"

project "Hazel"
	location "Hazel"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


 	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"

 	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",

	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"no_init_all=deprecated"
	}

 	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
	}

	links
	{
		"GLFW",
		"glad",
		"opengl32.lib",
		"ImGui"
	}

 	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

 		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


 	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		buildoptions "/MTd"
		symbols "On"

 	filter "configurations:Release"
		defines "HZ_RELEASE"
		buildoptions "/MTd"
		optimize "On"
		runtime "Release"

 	filter "configurations:Dist"
		defines "HZ_DIST"
		buildoptions "/MTd"
		optimize "On"
		runtime "Release"

 project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"
	cppdialect "C++17"


 	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

 	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src",
		"%{IncludeDir.glm}",
		"Hazel/vendor",
	}

 	links
	{
		"Hazel"
	}

 	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

 		defines
		{
			"HZ_PLATFORM_WINDOWS"
		}

 	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "debug"
		buildoptions "/MTd"
		symbols "On"

 	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "release"
		buildoptions "/MTd"
		optimize "On"

 	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "release"
		buildoptions "/MTd"
		optimize "On" 