newoption
{
	trigger = "os",
	value = "system",
	description = "Choose the target system",
	allowed =
	{
		{ "windows", "Windows" },
		{ "linux", "Linux" },
		{ "emscripten", "Emscripten" }
	}
}
local targetSystem = _OPTIONS["os"]
targetSystem = targetSystem:gsub("^%l", string.upper)

if not targetSystem then
	error("Error: You must provide the '--os' option to specify the target system (e.g., --os=windows or --os=linux).")
end

local baseDir 			= "../"
local binDir 			= baseDir .. "Bin/"
local buildDir 			= baseDir .. "Build/"
local dependenciesDir 	= baseDir .. "Dependencies/"
local projectDir 		= baseDir .. "Project/"
local sourceDir 		= baseDir .. "Source/"

local projectOutputDir = buildDir .. targetSystem .. "_Premake5/"
local binOutputDir = binDir .. targetSystem .. "/%{cfg.buildcfg}/"

function setupCommonProjectSettings(_projectName, _kind)

	location (projectOutputDir)
	kind (_kind)
	language "C++"
	cppdialect "C++20"
	warnings "Default"
	staticruntime "On"
	
	targetdir (binOutputDir)
	objdir (projectOutputDir .. "/Temp/" .. _projectName .. "/")
	
	files
	{
		sourceDir .. _projectName .. "/**.h",
		sourceDir .. _projectName .. "/**.cpp",
		dependenciesDir .. "imgui-docking" .. "/**.h",
		dependenciesDir .. "imgui-docking" .. "/**.cpp",
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
		dependenciesDir .. "imgui-docking",
		dependenciesDir .. "imgui-docking/backends"
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
	
	filter { "files:" .. dependenciesDir .. "**.cpp" }
		flags { 'NoPCH' }
	
	filter {}

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
	
	elseif targetSystem == "Emscripten" then
		toolset "clang"
		architecture "x86"
		staticruntime "Off"
		symbols "On"
		optimize "Off"
		
		defines
		{
			"_EMSCRIPTEN",
			"EMSCRIPTEN"
		}
		
		buildoptions
		{
			--"-gsource-map",
			--"-s USE_SDL=2",
			--"-s USE_SDL_IMAGE=2",
			--"-s USE_SDL_TTF=2",
			--"-s USE_SDL_MIXER=2"
			"-g4"
		}
		
		linkoptions
		{
			--"--bind",
			--"-s USE_SDL=2",
			--"-s USE_SDL_IMAGE=2",
			--"-s USE_SDL_TTF=2",
			--"-s USE_SDL_MIXER=2",
			--"--preload-file ../../../Assets",
			--"--preload-file ../../../Config",
			
			"-g4", 
			"--source-map-base http://localhost:8000/web/",
			"-s STACK_OVERFLOW_CHECK=1", 
			"-s SAFE_HEAP=1", 
			"-s DETERMINISTIC=1" 
		}
	
	end

end

--------------------------------------------------------------------------------

workspace "SDL2_Engine_Project"
	location (projectOutputDir)
	architecture "x64"
	startproject "Application"

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
	
	filter "configurations:Distribution"
		kind "WindowedApp"
	
	filter {}
	
	if targetSystem == "Emscripten" then
		targetextension ".html"
	
	end
	
	links
	{
		"System"
	}