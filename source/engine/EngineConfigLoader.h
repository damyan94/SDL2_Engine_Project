#ifndef ENGINE_ENGINECONFIGLOADER_H_
#define ENGINE_ENGINECONFIGLOADER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "engine/config/EngineConfig.h"

// Forward declarations

class EngineConfigLoader
{
public:
	EngineConfigLoader();
	~EngineConfigLoader();

	bool				Init();
	void				Deinit();

	EngineConfig*		GetConfig() const;

private:
	bool ReadAssetManagerConfig(AssetManagerConfig& cfg);
	bool ReadDrawManagerConfig(DrawManagerConfig& cfg);
	bool ReadTimerManagerConfig(TimerManagerConfig& cfg);
	bool ReadImGuiManagerConfig(ImGuiManagerConfig& cfg);

	bool ReadManagerHandlerConfig(ManagerHandlerConfig& cfg);

	bool ReadImageContainerConfig(ImageContainerConfig& cfg);
	bool ReadFontContainerConfig(FontContainerConfig& cfg);
	bool ReadSoundContainerConfig(SoundContainerConfig& cfg);
	bool ReadMusicContainerConfig(MusicContainerConfig& cfg);

	bool ReadWindowConfig(WindowConfig& cfg);
	bool ReadRendererConfig(RendererConfig& cfg);


	bool ReadAppConfig(AppConfig& cfg);

private:
	EngineConfig*		m_EngineConfig;
};

#endif // !ENGINE_ENGINECONFIGLOADER_H_