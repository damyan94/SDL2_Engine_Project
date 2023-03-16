// Corresponding header
#include "app/App.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/audio/Audio.h"

// =============================================================================
App::App()
{
}

// =============================================================================
App::~App()
{
}

// =============================================================================
bool App::Init()
{
	timer.Start(1000, ETimerType::Pulse);
	time.Init(Time::GetNow().GetString(ETimeStringFormat::yyyymmddHHmmss_Dots), FontId::Consola_18, Colors::Black);
	time.SetPos(50, 50);

	m_Logo.Init(ImageId::Logo);
	m_Logo.SetPos(300, 50);

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
		Audio::PlaySound(SoundId::MouseClick);
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
	m_Logo.Draw();
}