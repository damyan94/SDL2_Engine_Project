#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

#include "sdl_utils/Window.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/input/InputEvent.h"

#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/FontContainer.h"
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

#include "app/App.h"

// Forward declarations

class Engine
{
public:
	int32_t						Init();
	void						Deinit();
	void						HandleEvent();
	void						Update();
	void						Draw() const;

	void						RunApplication();

private:
	void						Sleep(int64_t elapsedTime);

private:
	Window						m_Window;
	Renderer					m_Renderer;
	InputEvent					m_InputEvent;

	ImageContainer				m_ImageContainer;
	FontContainer				m_FontContainer;
	SoundContainer				m_SoundContainer;
	MusicContainer				m_MusicContainer;

	App							m_App;

	TimerId						m_DrawTimerId = 0;
	int64_t						m_CurrFPS = 0;
};

#endif // !ENGINE_ENGINE_H_