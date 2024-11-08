#pragma once

#include "System/Components/UI/Components/Config/ButtonConfig.h"
#include "System/Components/UI/Components/Config/CheckboxConfig.h"
#include "System/Components/UI/Components/Config/RadioButtonConfig.h"
#include "System/Components/UI/Components/Config/TextBoxConfig.h"

struct StartMenuConfig
{
	bool				Read(const ConfigStrings& readStrings);

	Rectangle			m_PosRect;

	ButtonConfig	    m_ButtonNewGameConfig;
	ButtonConfig	    m_ButtonSettingsConfig;
	ButtonConfig	    m_ButtonQuitConfig;
};