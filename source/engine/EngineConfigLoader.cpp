// Corresponding header
#include "engine/EngineConfigLoader.h"

// C/C++ system includes
#include <sstream>

// Third-party includes

// Own includes
#include "defines/consts/GlobalConstants.h"
#include "utils/others/CodeReadabilityDefines.h"
#include "utils/input_output/ReadWriteFile.h"
#include "engine/config/EngineConfig.h"
#include "engine/EngineConfigLoaderUtils.h"

namespace ConfigFilePaths
{
	static const std::string Window			= "./config/sdl/window.cfg";
	static const std::string Renderer		= "./config/sdl/renderer.cfg";

	static const std::string ImageContainer	= "./config/assets/images.cfg";
	static const std::string FontContainer	= "./config/assets/fonts.cfg";
	static const std::string SoundContainer	= "./config/assets/sounds.cfg";
	static const std::string MusicContainer	= "./config/assets/musics.cfg";
} // !ConfigFilePaths

// =============================================================================
EngineConfigLoader::EngineConfigLoader()
	: m_EngineConfig(nullptr)
{
}

// =============================================================================
EngineConfigLoader::~EngineConfigLoader()
{
	Deinit();
}

//TODO How to make the configite to work?
// 1. Do I read all the config data from one massive file and dispatch it - the Gameloft way? Maybe this and have it all static as Zhivko did?
// 2. Do I read separate configs in the respective file via a Read() method?
// 3. Do I do something completely different?
// =============================================================================
bool EngineConfigLoader::Init()
{
	m_EngineConfig = new EngineConfig;

	ReturnIf(!ReadManagerHandlerConfig(m_EngineConfig->m_ManagerHandlerConfig), false);
	ReturnIf(!ReadAppConfig(m_EngineConfig->m_AppConfig), false);

	return true;
}

// =============================================================================
void EngineConfigLoader::Deinit()
{
	SafeDelete(m_EngineConfig);
}

// =============================================================================
EngineConfig* EngineConfigLoader::GetConfig() const
{
	return m_EngineConfig;
}

// =============================================================================
bool EngineConfigLoader::ReadManagerHandlerConfig(ManagerHandlerConfig& cfg)
{
	ReturnIf(!ReadDrawManagerConfig(cfg.m_DrawManagerConfig), false);
	ReturnIf(!ReadAssetManagerConfig(cfg.m_AssetManagerConfig), false);
	ReturnIf(!ReadTimerManagerConfig(cfg.m_TimerManagerConfig), false);

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadDrawManagerConfig(DrawManagerConfig& cfg)
{
	ReturnIf(!ReadWindowConfig(cfg.m_WindowConfig), false);
	ReturnIf(!ReadRendererConfig(cfg.m_RendererConfig), false);

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadAssetManagerConfig(AssetManagerConfig& cfg)
{
	ReturnIf(!ReadImageContainerConfig(cfg.m_ImageContainerConfig), false);
	ReturnIf(!ReadFontContainerConfig(cfg.m_FontContainerConfig), false);
	ReturnIf(!ReadSoundContainerConfig(cfg.m_SoundContainerConfig), false);
	ReturnIf(!ReadMusicContainerConfig(cfg.m_MusicContainerConfig), false);

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadTimerManagerConfig(TimerManagerConfig& cfg)
{
	//TODO Read Timer configs
	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadImGuiManagerConfig(ImGuiManagerConfig& cfg)
{
	//TODO Read data from file and populate the config
	cfg.m_ImGuiStyle = EImGuiStyle::Dark;

	return true;
}


// =============================================================================
bool EngineConfigLoader::ReadImageContainerConfig(ImageContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReadWriteFile::ReadFromFile(ConfigFilePaths::ImageContainer, readStrings);
	AssertReturnIf(readStrings.size() != (size_t)ImageId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::ImageContainer);
	
	for (size_t i = 0; i < (size_t)ImageId::Count; i++)
	{
		ImageConfig newCfg;
		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		newCfg.m_Frames = Utils::ReadInt(readStrings[i], "frames");
	
		cfg.m_ImageContainerConfig[ImageId(i)] = newCfg;
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadFontContainerConfig(FontContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReadWriteFile::ReadFromFile(ConfigFilePaths::FontContainer, readStrings);
	AssertReturnIf(readStrings.size() != (size_t)FontId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::FontContainer);

	for (size_t i = 0; i < (size_t)FontId::Count; i++)
	{
		FontConfig newCfg;
		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");
		newCfg.m_Size = Utils::ReadInt(readStrings[i], "size");

		cfg.m_FontContainerConfig[FontId(i)] = newCfg;
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadSoundContainerConfig(SoundContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReadWriteFile::ReadFromFile(ConfigFilePaths::SoundContainer, readStrings);
	AssertReturnIf(readStrings.size() != (size_t)SoundId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::SoundContainer);

	for (size_t i = 0; i < (size_t)SoundId::Count; i++)
	{
		SoundConfig newCfg;
		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");

		cfg.m_SoundContainerConfig[SoundId(i)] = newCfg;
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadMusicContainerConfig(MusicContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReadWriteFile::ReadFromFile(ConfigFilePaths::MusicContainer, readStrings);
	AssertReturnIf(readStrings.size() != (size_t)MusicId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::MusicContainer);

	for (size_t i = 0; i < (size_t)MusicId::Count; i++)
	{
		MusicConfig newCfg;
		newCfg.m_FileName = Utils::ReadString(readStrings[i], "file_name");

		cfg.m_MusicContainerConfig[MusicId(i)] = newCfg;
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadWindowConfig(WindowConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReadWriteFile::ReadFromFile(ConfigFilePaths::Window, readStrings);
	AssertReturnIf(readStrings.size() != 6, false, "Config file corrupted: " + ConfigFilePaths::Window);

	cfg.m_Name		= Utils::ReadString(readStrings[0], "title");
	cfg.m_PosX		= Utils::ReadInt(readStrings[1], "pos_x"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	cfg.m_PosY		= Utils::ReadInt(readStrings[2], "pos_y"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	cfg.m_Width		= Utils::ReadInt(readStrings[3], "width");
	cfg.m_Height	= Utils::ReadInt(readStrings[4], "height");
	cfg.m_Flags		= Utils::ReadInt(readStrings[5], "flags"); //default 0x00000004 SDL_WINDOW_SHOWN

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadRendererConfig(RendererConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReadWriteFile::ReadFromFile(ConfigFilePaths::Renderer, readStrings);
	AssertReturnIf(readStrings.size() != 2, false, "Config file corrupted: " + ConfigFilePaths::Renderer);

	auto colorData = Utils::ReadIntArray(readStrings[0], "color", 4);
	AssertReturnIf(colorData.size() != 4, false, "Config file corrupted: " + ConfigFilePaths::Renderer);

	cfg.m_Color.r = colorData[0]; //default Colors::VeryLightGrey
	cfg.m_Color.g = colorData[1];
	cfg.m_Color.b = colorData[2];
	cfg.m_Color.a = colorData[3];

	cfg.m_Flags = Utils::ReadInt(readStrings[1], "flags"); //default 0x00000002 SDL_RENDERER_ACCELERATED;

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadAppConfig(AppConfig& cfg)
{
	//TODO Read App configs
	return true;
}