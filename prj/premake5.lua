newoption
{
    trigger = "os",
    value = "system",
    description = "Choose the target system",
    allowed =
	{
		{ "windows", "Windows" },
		{ "linux", "Linux" }
    }
}
local targetSystem = _OPTIONS["os"]
targetSystem = targetSystem:gsub("^%l", string.upper)

if not targetSystem then
    error("Error: You must provide the '--os' option to specify the target system (e.g., --os=windows or --os=linux).")
end

local baseDir 			= "../"
local buildDir 			= baseDir .. "build/"
local dependenciesDir 	= baseDir .. "dependencies/"
local projectDir 		= baseDir .. "prj/"
local sourceDir 		= baseDir .. "source/"

local outputDir = buildDir .. targetSystem .. "_%{cfg.architecture}_%{cfg.buildcfg}/"
	
function setupCommonProjectSettings(_projectName, _kind)

	location (projectDir .. targetSystem .. "/" .. _projectName)
	kind (_kind)
	language "C++"
	cppdialect "C++20"
	warnings "Default"
	staticruntime "On"
		
	targetdir (outputDir)
	objdir (outputDir .. "/Temp/" .. _projectName)
	
	files
	{
		sourceDir .. _projectName .. "/**.h",
		sourceDir .. _projectName .. "/**.cpp"
	}
	
	includedirs
	{
		baseDir,
		sourceDir,
		sourceDir .. _projectName,
		dependenciesDir .. "SDL2/SDL2/include",
		dependenciesDir .. "SDL2/SDL2_image/include",
		dependenciesDir .. "SDL2/SDL2_ttf/include",
		dependenciesDir .. "SDL2/SDL2_mixer/include",
		dependenciesDir .. "imgui-master",
		dependenciesDir .. "imgui-master/backends"
	}
	
	libdirs
	{
		dependenciesDir .. "SDL2/SDL2/lib/x64",
		dependenciesDir .. "SDL2/SDL2_image/lib/x64",
		dependenciesDir .. "SDL2/SDL2_ttf/lib/x64",
		dependenciesDir .. "SDL2/SDL2_mixer/lib/x64"
	}
	
	links
	{
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
	pchsource (sourceDir .. _projectName .. "/stdafx.cpp")
	
end

function setupConfigurationSpecificSettings()

	filter "configurations:Debug"
		symbols "On"
		
		defines
		{
			"_DEBUG",
			"DEBUG"
		}
		
	filter "configurations:Release"
		symbols "On"
		optimize "On"
		
		defines
		{
			"_RELEASE",
			"RELEASE"
		}
		
	filter "configurations:Distribution"
		optimize "On"
		
		defines
		{
			"_DISTRIBUTION",
			"DISTRIBUTION"
		}
		
	filter {}
	
end

function setupPlatformSpecificSettings()

	if targetSystem == "Windows" then
		systemversion "latest"
		characterset ("ASCII")
		entrypoint "mainCRTStartup"
		
		defines
		{
			"_WIN32",
			"_WIN64",
			"WIN32",
			"WIN64",
			"_WINDOWS",
			"WINDOWS"
		}
		
	elseif targetSystem == "Linux" then
		defines
		{
			"__linux__",
			"_LINUX",
			"LINUX"
		}
			
	end

end

--------------------------------------------------------------------------------

workspace "SDL2_Engine_Project"
	location (projectDir .. targetSystem .. "/")
	architecture "x64"
	startproject "System"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}
	
project "System"
	setupCommonProjectSettings("%{prj.name}", "StaticLib")
	setupConfigurationSpecificSettings()
	setupPlatformSpecificSettings()
		
project "Application"
	setupCommonProjectSettings("%{prj.name}", "ConsoleApp")
	setupConfigurationSpecificSettings()
	setupPlatformSpecificSettings()
	
	links
	{
		"System"
	}