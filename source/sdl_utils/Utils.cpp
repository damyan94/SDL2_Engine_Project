// Corresponding header
#include "sdl_utils/Utils.h"

// C/C++ system includes

// Third-party includes

// Own includes

namespace Utils
{
// =============================================================================
ELanguage GetLanguageIdFromString(const std::string& langString)
{
	if (langString == "bg") return ELanguage::BG;
	if (langString == "en") return ELanguage::EN;

	return ELanguage::Invalid;
}

// =============================================================================
std::string GetLanguageStringFromId(ELanguage id)
{
	if (id == ELanguage::BG) return "bg";
	if (id == ELanguage::EN) return "en";

	return "";
}
} // !namespace Utils