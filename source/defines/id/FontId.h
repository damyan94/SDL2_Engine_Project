#ifndef DEFINES_ID_FONTID_H_
#define DEFINES_ID_FONTID_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

//TODO Maybe move this to .cfg file
enum class FontId
	: int32_t
{
	Invalid = -1

	, Consola_12
	, Consola_14
	, Consola_18

	, Count
};

#endif // !DEFINES_ID_FONTID_H_