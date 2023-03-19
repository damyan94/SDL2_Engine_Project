// Corresponding header
#include "engine/EngineConfigLoader.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/ReadWriteFile.h"
#include "engine/config/EngineConfig.h"
#include "engine/EngineConfigLoaderUtils.h"

namespace ConfigFilePaths
{
	static const std::string Window			= "./config/sdl/window.cfg";
	static const std::string Renderer		= "./config/sdl/renderer.cfg";

	static const std::string ImageContainer	= "./config/assets/images.cfg";
	static const std::string TextContainer	= "./config/assets/texts.cfg";
	static const std::string FontContainer	= "./config/assets/fonts.cfg";
	static const std::string SoundContainer	= "./config/assets/sounds.cfg";
	static const std::string MusicContainer	= "./config/assets/musics.cfg";
} // !ConfigFilePaths

// =============================================================================
bool EngineConfigLoader::ReadEngineConfig(EngineConfig& cfg)
{
	ReturnIf(!ReadManagerHandlerConfig(cfg.m_ManagerHandlerConfig), false);
	ReturnIf(!ReadAppConfig(cfg.m_AppConfig), false);

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadManagerHandlerConfig(ManagerHandlerConfig& cfg)
{
	ReturnIf(!ReadDrawManagerConfig(cfg.m_DrawManagerConfig), false);
	ReturnIf(!ReadAssetManagerConfig(cfg.m_AssetManagerConfig), false);
	ReturnIf(!ReadAudioManagerConfig(cfg.m_AudioManagerConfig), false);
	ReturnIf(!ReadTimerManagerConfig(cfg.m_TimerManagerConfig), false);

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadAppConfig(AppConfig& cfg)
{
	//TODO Read App configs
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
	ReturnIf(!ReadTextContainerConfig(cfg.m_TextContainerConfig), false);
	ReturnIf(!ReadFontContainerConfig(cfg.m_FontContainerConfig), false);
	ReturnIf(!ReadSoundContainerConfig(cfg.m_SoundContainerConfig), false);
	ReturnIf(!ReadMusicContainerConfig(cfg.m_MusicContainerConfig), false);

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadAudioManagerConfig(AudioManagerConfig& cfg)
{
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
bool EngineConfigLoader::ReadWindowConfig(WindowConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::Window, readStrings), false);
	AssertReturnIf(readStrings.size() != 6, false,
		"Config file corrupted, too many or too few lines: " + ConfigFilePaths::Window);

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
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::Renderer, readStrings), false);
	AssertReturnIf(readStrings.size() != 2, false, "Config file corrupted: " + ConfigFilePaths::Renderer);

	auto colorData = Utils::ReadIntArray(readStrings[0], "color", 4);
	AssertReturnIf(colorData.size() != 4, false, "Config file corrupted: " + ConfigFilePaths::Renderer);

	cfg.m_Color.r	= colorData[0]; //default Colors::VeryLightGrey
	cfg.m_Color.g	= colorData[1];
	cfg.m_Color.b	= colorData[2];
	cfg.m_Color.a	= colorData[3];

	cfg.m_Flags		= Utils::ReadInt(readStrings[1], "flags"); //default 0x00000002 SDL_RENDERER_ACCELERATED;

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadImageContainerConfig(ImageContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::ImageContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)ImageId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::ImageContainer);
	
	for (size_t i = 0; i < (size_t)ImageId::Count; i++)
	{
		ImageConfig newCfg;
		newCfg.m_FileName	= Utils::ReadString(readStrings[i], "file_name");
		newCfg.m_Frames		= Utils::ReadInt(readStrings[i], "frames");
	
		cfg.m_ImageContainerConfig.emplace(ImageId(i), std::move(newCfg));
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadFontContainerConfig(FontContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::FontContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)FontId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::FontContainer);

	for (size_t i = 0; i < readStrings.size(); i++)
	{
		FontConfig newCfg;
		newCfg.m_FileName	= Utils::ReadString(readStrings[i], "file_name");
		newCfg.m_Size		= Utils::ReadInt(readStrings[i], "size");

		cfg.m_FontContainerConfig.emplace(FontId(i), std::move(newCfg));
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadTextContainerConfig(TextContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::TextContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)TextId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::TextContainer);

	for (size_t i = 0; i < readStrings.size(); i++)
	{
		TextConfig newCfg;
		std::string temp	= Utils::ReadString(readStrings[i], "string");
		newCfg.m_String		= String(temp.begin(), temp.end());

		auto color			= Utils::ReadIntArray(readStrings[i], "color", 4);
		AssertReturnIf(color.size() != 4, false, "Config file corrupted: " +
			ConfigFilePaths::TextContainer + "Invalid color data. Line: " + std::to_string(i));

		newCfg.m_TextColor	= Color(color[0], color[1], color[2], color[3]);
		newCfg.m_FontId		= FontId(Utils::ReadInt(readStrings[i], "font_id"));

		cfg.m_TextContainerConfig.emplace(TextId(i), std::move(newCfg));
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadSoundContainerConfig(SoundContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::SoundContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)SoundId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::SoundContainer);

	for (size_t i = 0; i < readStrings.size(); i++)
	{
		SoundConfig newCfg;
		newCfg.m_FileName	= Utils::ReadString(readStrings[i], "file_name");
		newCfg.m_Volume		= Utils::ReadInt(readStrings[i], "volume");

		cfg.m_SoundContainerConfig.emplace(SoundId(i), std::move(newCfg));
	}

	return true;
}

// =============================================================================
bool EngineConfigLoader::ReadMusicContainerConfig(MusicContainerConfig& cfg)
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::MusicContainer, readStrings), false);
	AssertReturnIf(readStrings.size() != (size_t)MusicId::Count, false,
		"Config file corrupted: " + ConfigFilePaths::MusicContainer);

	for (size_t i = 0; i < readStrings.size(); i++)
	{
		MusicConfig newCfg;
		newCfg.m_FileName	= Utils::ReadString(readStrings[i], "file_name");
		newCfg.m_Volume		= Utils::ReadInt(readStrings[i], "volume");

		cfg.m_MusicContainerConfig.emplace(MusicId(i), std::move(newCfg));
	}

	return true;
}