#ifndef ENGINE_SETTINGS_SETTINGS_H_
#define ENGINE_SETTINGS_SETTINGS_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

// Forward declarations

class Settings
{
public:
	Settings();
	~Settings();

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

#endif // !ENGINE_SETTINGS_SETTINGS_H_