#pragma once

class Settings
{
public:
	Settings();
	~Settings();

	Settings(const Settings& other) = delete;
	Settings(Settings&& other) = delete;

	Settings& operator=(const Settings& other) = delete;
	Settings& operator=(Settings&& other) = delete;

	bool				Read();
	bool				Write();

	int32_t				GetTargetFPS() const;
	ELanguage			GetLanguage() const;

	void				SetTargetFPS(int32_t targetFPS);
	void				SetLanguage(ELanguage language);

private:
	int32_t				m_TargetFPS;
	ELanguage			m_Language;
};

extern Settings* const g_Settings;