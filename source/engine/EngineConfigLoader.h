#ifndef ENGINE_ENGINECONFIGLOADER_H_
#define ENGINE_ENGINECONFIGLOADER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "engine/config/EngineConfig.h"

// Forward declarations

namespace EngineConfigLoader
{
bool ReadEngineConfig(EngineConfig& cfg);
bool ReadManagerHandlerConfig(ManagerHandlerConfig& cfg);
bool ReadAppConfig(AppConfig& cfg);

bool ReadDrawManagerConfig(DrawManagerConfig& cfg);
bool ReadAssetManagerConfig(AssetManagerConfig& cfg);
bool ReadAudioManagerConfig(AudioManagerConfig& cfg);
bool ReadTimerManagerConfig(TimerManagerConfig& cfg);
bool ReadImGuiManagerConfig(ImGuiManagerConfig& cfg);

bool ReadWindowConfig(WindowConfig& cfg);
bool ReadRendererConfig(RendererConfig& cfg);

bool ReadImageContainerConfig(ImageContainerConfig& cfg);
bool ReadFontContainerConfig(FontContainerConfig& cfg);
bool ReadTextContainerConfig(TextContainerConfig& cfg);
bool ReadSoundContainerConfig(SoundContainerConfig& cfg);
bool ReadMusicContainerConfig(MusicContainerConfig& cfg);
};

#endif // !ENGINE_ENGINECONFIGLOADER_H_