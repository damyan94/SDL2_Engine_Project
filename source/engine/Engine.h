#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/Window.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/input/InputEvent.h"

#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/FontContainer.h"
#include "sdl_utils/containers/SoundContainer.h"
#include "sdl_utils/containers/MusicContainer.h"

#include "game/Game.h"

// Forward declarations

class Engine
{
public:
	int32_t Init();
	void Deinit();
	void HandleEvent();
	void Update();
	void Draw() const;

	void RunApplication();

private:
	void Sleep(int64_t elapsedTime);

private:
	Window _window;
	Renderer _renderer;
	InputEvent _event;

	ImageContainer _imageContainer;
	FontContainer _fontContainer;
	SoundContainer _soundContainer;
	MusicContainer _musicContainer;

	Game _game;

	int32_t _drawTimerId = 0;
	int64_t _currFPS = 0;
};

#endif // !ENGINE_ENGINE_H_