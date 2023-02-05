// Corresponding header
#include "defines/FontDefines.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
FontData::FontData()
	: m_FileName("")
	, m_Id(FontId::Invalid)
	, m_Size(0)
{
}

// =============================================================================
FontData::~FontData()
{
}

// =============================================================================
FontData::FontData(const char* fileName, FontId id, uint32_t size)
	: m_FileName(fileName)
	, m_Id(id)
	, m_Size(size)
{
}

// =============================================================================
//TODO Move all this to a .cfg file
const std::vector<FontData> g_FontsData =
{
	{"assets/fonts/Consola.ttf", FontId::Consola_12, 12}
	, {"assets/fonts/Consola.ttf", FontId::Consola_14, 14}
	, {"assets/fonts/Consola.ttf", FontId::Consola_18, 18}
};