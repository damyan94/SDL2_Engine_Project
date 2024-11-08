#ifndef APPLICATION_APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_APPLICATION_H_

#include "system/sdl_utils/input/InputEvent.h"

struct ApplicationConfig;

class Application
{
public:
	Application();
	~Application();

	bool				Init(const ApplicationConfig& cfg);
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

#endif // !APPLICATION_APPLICATION_APPLICATION_H_