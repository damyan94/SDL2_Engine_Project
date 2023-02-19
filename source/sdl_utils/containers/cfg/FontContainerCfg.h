#ifndef DEFINES_FONTDEFINES_H_
#define DEFINES_FONTDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"

// Forward declarations

struct FontCfg
{
	FontCfg();
	~FontCfg();

	FontCfg(const char* fileName, FontId id, uint32_t size);

	const char*			m_FileName;
	FontId				m_Id;
	uint32_t			m_Size;
};

typedef std::vector<FontCfg> FontCfgsContainer;

class FontContainerCfg
{
public:
	FontContainerCfg();
	~FontContainerCfg();

	bool				Read();
	FontCfgsContainer	GetData() const;

private:
	FontCfgsContainer	m_FontsCfgData;
};

#endif // !DEFINES_FONTDEFINES_H_