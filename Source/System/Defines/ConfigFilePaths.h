#pragma once

//TODO rename to FilePaths
namespace ConfigFilePaths
{
inline std::string ConfigFilePath(const std::string& path)
{
#if defined _DISTRIBUTION
	return path;

#elif defined _DEBUG || _RELEASE
#if defined _LINUX || __linux__
	return "../../../" + path;
#elif defined _WINDOWS || _WIN32 || WIN32
	// When you start the program through Visual Studio the paths are relative to the .vcxproj file, not the .exe
	return "../../" + path;
#endif

#endif // !_DEBUG || _RELEASE
}

static const std::string AssetsDir			= ConfigFilePath("Assets/");
static const std::string ConfigDir			= ConfigFilePath("Config/");
static const std::string LogsDir			= ConfigFilePath("Logs/");

//TODO I should have on file containing the file paths to the different configs instead of hardcoding them
static const std::string SystemConfig		= ConfigFilePath("Config/System.cfg");

static const std::string ImageConfig		= ConfigFilePath("Config/Image.cfg");
static const std::string StringConfig		= ConfigFilePath("Config/String.cfg");
static const std::string FontConfig			= ConfigFilePath("Config/Font.cfg");
static const std::string TextConfig			= ConfigFilePath("Config/Text.cfg");
static const std::string SoundConfig		= ConfigFilePath("Config/Sound.cfg");
static const std::string MusicConfig		= ConfigFilePath("Config/Music.cfg");

static const std::string ImageBoxConfig		= ConfigFilePath("Config/ImageBox.cfg");
static const std::string LabelConfig		= ConfigFilePath("Config/Label.cfg");
static const std::string ButtonConfig		= ConfigFilePath("Config/Button.cfg");
static const std::string CheckboxConfig		= ConfigFilePath("Config/Checkbox.cfg");
static const std::string RadioButtonConfig	= ConfigFilePath("Config/RadioButton.cfg");
static const std::string TextBoxConfig		= ConfigFilePath("Config/TextBox.cfg");

static const std::string MenuConfig			= ConfigFilePath("Config/Menu.cfg");
} // !ConfigFilePaths