// Corresponding header
#include "sdl_utils/containers/cfg/FontContainerCfg.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
FontCfg::FontCfg()
	: m_FileName("")
	, m_Id(FontId::Invalid)
	, m_Size(0)
{
}

// =============================================================================
FontCfg::FontCfg(const char* fileName, FontId id, uint32_t size)
	: m_FileName(fileName)
	, m_Id(id)
	, m_Size(size)
{
}

// =============================================================================
FontCfg::~FontCfg()
{
}

// =============================================================================
FontContainerCfg::FontContainerCfg()
{
}

// =============================================================================
FontContainerCfg::~FontContainerCfg()
{
}

// =============================================================================
//TODO To be called from the ConfigsManager
bool FontContainerCfg::Read()
{
	//TODO Read data from file and populate the config
	m_FontsCfgData =
	{
		{"assets/fonts/Consola.ttf", FontId::Consola_12, 12}
		, {"assets/fonts/Consola.ttf", FontId::Consola_14, 14}
		, {"assets/fonts/Consola.ttf", FontId::Consola_18, 18}
	};

	return true;
}

// =============================================================================
FontCfgsContainer FontContainerCfg::GetData() const
{
	return m_FontsCfgData;
}