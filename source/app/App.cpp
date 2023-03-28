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

	text.Init(/*TextId::TestId*/1200000);
	text.SetPos(50, 250);

	m_Logo.Init(/*ImageId::Logo*/1000000);
	m_Logo.SetPos(300, 50);

	m_Click.Init(/*SoundId::MouseClick*/1300000);

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
		m_Click.Play();
	}
}

// =============================================================================
void App::Update(int32_t dt)
{
	ReturnIf(!timer.IsTicked(), void());

	time.SetText(Time::GetNow().GetString(ETimeStringFormat::yyyymmddHHmmss_Dots));
}

// =============================================================================
void App::Draw() const
{
	time.Draw();
	text.Draw();

	m_Logo.Draw();
}