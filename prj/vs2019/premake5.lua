workspace "SDL2_Engine_Project"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "../../build/%{cfg.system}_%{cfg.architecture}_%{cfg.buildcfg}"

project "System"
	location "%{prj.name}"
	kind "StaticLib"
	language "C++"
	
	warnings "Default"
	characterset ("ASCII")
	
	targetdir (outputdir)
	objdir (outputdir .. "/Temp/%{prj.name}")
	
	files
	{
		"../../source/%{prj.name}/**.h",
		"../../source/%{prj.name}/**.cpp"
	}
	
	includedirs
	{
		"../../",
		"../../source",
		"../../source/%{prj.name}",
		"../../dependencies/SDL2/SDL2/include",
		"../../dependencies/SDL2/SDL2_image/include",
		"../../dependencies/SDL2/SDL2_ttf/include",
		"../../dependencies/SDL2/SDL2_mixer/include",
		"../../dependencies/imgui-master",
		"../../dependencies/imgui-master/backends",
		"../../dependencies/GLEW/include"
	}
	
	libdirs
	{
		"../../dependencies/GLEW/lib/Release/x64",
		"../../dependencies/GLEW/bin/Release/x64",
		"../../dependencies/SDL2/SDL2/lib/x64",
		"../../dependencies/SDL2/SDL2_image/lib/x64",
		"../../dependencies/SDL2/SDL2_ttf/lib/x64",
		"../../dependencies/SDL2/SDL2_mixer/lib/x64"
	}
	
	links
	{
		"opengl32",
		"glew32",
		"SDL2",
		"SDL2_image",
		"SDL2_ttf",
		"SDL2_mixer"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}
	
	pchheader "stdafx.h"
	pchsource "../../source/%{prj.name}/stdafx.cpp"
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"_WIN32",
			"_WIN64",
			"WIN32",
			"WIN64",
		}
		
		postbuildcommands
		{
			
		}
	
	filter "configurations:Debug"
		symbols "On"
		
		defines
		{
			"_DEBUG"
		}
		
	filter "configurations:Release"
	optimize "On"
		
		defines
		{
			"_RELEASE"
		}
		
	filter "configurations:Distribution"
	optimize "On"
		
		defines
		{
			"_DISTRIBUTION"
		}
		
project "Application"
	location "%{prj.name}"
	kind "ConsoleApp"
	language "C++"
	
	warnings "Default"
	characterset ("ASCII")
	
	targetdir (outputdir)
	objdir (outputdir .. "/Temp/%{prj.name}")
	
	files
	{
		"../../source/%{prj.name}/**.h",
		"../../source/%{prj.name}/**.cpp"
	}
	
	includedirs
	{
		"../../",
		"../../source",
		"../../source/%{prj.name}",
		"../../dependencies/SDL2/SDL2/include",
		"../../dependencies/SDL2/SDL2_image/include",
		"../../dependencies/SDL2/SDL2_ttf/include",
		"../../dependencies/SDL2/SDL2_mixer/include",
		"../../dependencies/imgui-master",
		"../../dependencies/imgui-master/backends",
		"../../dependencies/GLEW/include"
	}
	
	libdirs
	{
		"../../dependencies/GLEW/lib/Release/x64",
		"../../dependencies/GLEW/bin/Release/x64",
		"../../dependencies/SDL2/SDL2/lib/x64",
		"../../dependencies/SDL2/SDL2_image/lib/x64",
		"../../dependencies/SDL2/SDL2_ttf/lib/x64",
		"../../dependencies/SDL2/SDL2_mixer/lib/x64"
	}
	
	links
	{
		"opengl32",
		"glew32",
		"SDL2",
		"SDL2_image",
		"SDL2_ttf",
		"SDL2_mixer",
		"System"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}
	
	pchheader "stdafx.h"
	pchsource "../../source/%{prj.name}/stdafx.cpp"
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"_WIN32",
			"_WIN64",
			"WIN32",
			"WIN64",
		}
		
		postbuildcommands
		{
			
		}
	
	filter "configurations:Debug"
		symbols "On"
		
		defines
		{
			"_DEBUG"
		}
		
	filter "configurations:Release"
	optimize "On"
		
		defines
		{
			"_RELEASE"
		}
		
	filter "configurations:Distribution"
	optimize "On"
		
		defines
		{
			"_DISTRIBUTION"
		}