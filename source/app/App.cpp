// Corresponding header
#include "app/App.h"
#include "app/config/AppConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/time/Time.h"

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
	time.Init(Time::GetNow().GetString(ETimeStringFormat::yyyymmddHHmmss_Dots), 1100002, Colors::Black);
	time.SetPos(50, 50);

	text.Init(cfg.m_TextId);
	text.SetPos(50, 250);

	m_Logo.Init(cfg.m_ImageId);
	m_Logo.SetPos(300, 50);

	m_Click.Init(cfg.m_SoundId);

	ButtonConfig buttonCfg;
	buttonCfg.Read();
	m_Button.Init(buttonCfg);
	m_Button.SetPosition({ 100, 400 });

	return true;
}

// =============================================================================
void App::Deinit()
{
}

// =============================================================================
void App::HandleEvent(const InputEvent& e)
{
	if (e.m_Type == EEventType::MouseButtonDown)
	{
		//m_Click.Play();
	}
	m_Button.HandleEvent(e);
}

// =============================================================================
void App::Update(int32_t dt)
{
	ReturnIf(!timer.IsTicked(), void());

	time.SetText(Time::GetNow().GetString(ETimeStringFormat::yyyymmddHHmmss_Dots));

	m_Button.Update(dt);
}

// =============================================================================
void App::Draw() const
{
	for (int i = 0; i < 1; i++)
	{
		time.Draw();
		
		text.Draw();

		m_Logo.Draw();
	}

	m_Button.Draw();
}