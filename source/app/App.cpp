// Corresponding header
#include "app/App.h"
#include "app/config/AppConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/time/Time.h"
#include "utils/string/String.h"
#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

//#include "app/OpenGLExperiment.h"

// =============================================================================
App::App()
{
}

// =============================================================================
App::~App()
{
	Deinit();
}

// =============================================================================
bool App::Init(const AppConfig& cfg)
{
	timer.Start(1000, ETimerType::Pulse);
	time.Init(Time::GetNow().GetString(ETimeStringFormat::yyyymmddHHmmss_Dots), Utils::Hash("consola_18"), Colors::Black);
	time.SetPos(50, 50);

	m_Logo.Init(cfg.m_ImageId);
	m_Logo.SetPos(cfg.m_ImagePos);
	text.Init(cfg.m_TextId);
	text.SetPos(cfg.m_TextPos);

	m_StartMenu.Init(cfg.m_StartMenuConfig);

	//OpenGl::InitFlagTest();

	return true;
}

// =============================================================================
void App::Deinit()
{
}

// =============================================================================
void App::HandleEvent(const InputEvent& e)
{
	m_StartMenu.HandleEvent(e);
}

// =============================================================================
void App::Update(int32_t dt)
{
	time.SetText(Time::GetNow().GetString(ETimeStringFormat::yyyymmddHHmmss_Dots));

	m_StartMenu.Update(dt);
}

// =============================================================================
void App::Draw() const
{
	for (int i = 0; i < 1; i++)
	{
		time.Draw();
		m_Logo.Draw();
		text.Draw();
	}
	
	m_StartMenu.Draw();

	//OpenGl::DrawFlagTest();
}