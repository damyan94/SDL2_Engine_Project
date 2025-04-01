#pragma once

class Settings
	: public INonCopyMoveable
{
private:
	Settings();
	~Settings();

public:
	static Settings&	Instance();

	bool				Read();
	bool				Write();

	int32_t				GetTargetFPS() const;
	ELanguage			GetLanguage() const;

	void				SetTargetFPS(int32_t targetFPS);
	void				SetLanguage(ELanguage language);

private:
	File				m_SettingsFile;

	int32_t				m_TargetFPS;
	ELanguage			m_Language;
};