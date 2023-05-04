#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"
#include "sdl_utils/input/InputEvent.h"
#include "app/App.h"

// Forward declarations
struct EngineConfig;

class Engine
{
public:
	Engine();
	~Engine();

	bool				Init(const EngineConfig& cfg);
	void				Deinit();

	void				RunApplication();

private:
	void				HandleEvent();
	void				Update();
	void				Draw() const;

	void				Sleep();

private:
	InputEvent			m_InputEvent;

	int32_t				m_ElapsedTimeMS;
	int32_t				m_TargetFPS;
	int32_t				m_TargetTimePerFrame;
};

#endif // !ENGINE_ENGINE_H_