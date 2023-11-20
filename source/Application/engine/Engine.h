#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

#include "application/App.h"

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