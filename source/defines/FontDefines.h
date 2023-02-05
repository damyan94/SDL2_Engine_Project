#ifndef DEFINES_FONTDEFINES_H_
#define DEFINES_FONTDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"

// Forward declarations

struct FontData
{
	FontData();
	~FontData();

	FontData(const char* fileName, FontId id, uint32_t size);

	const char*			m_FileName;
	FontId				m_Id;
	uint32_t			m_Size;
};

extern const std::vector<FontData> g_FontsData;

#define FONTS_COUNT g_FontsData.size();

#endif // !DEFINES_FONTDEFINES_H_