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
}

// =============================================================================
bool App::Init(const AppConfig& cfg)
{
	timer.Start(1000, ETimerType::Pulse);
	time.Init(Time::GetNow().GetWString(ETimeStringFormat::yyyymmddHHmmss_Dots), FontId::Consola_18, Colors::Black);
	time.SetPos(50, 50);

	text.Init(TextId::TestId);
	text.SetPos(50, 250);
	text.SetTextColor(Colors::Blue);

	m_Logo.Init(ImageId::Logo);
	m_Logo.SetPos(300, 50);

	m_Click.Init(SoundId::MouseClick);

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

	time.SetText(Time::GetNow().GetWString(ETimeStringFormat::yyyymmddHHmmss_Dots));
}

// =============================================================================
void App::Draw() const
{
	time.Draw();
	text.Draw();
	m_Logo.Draw();
}