#ifndef APP_DEFINES_H_
#define APP_DEFINES_H_

// =============================================================================
// ================================= DEFINES ===================================
// =============================================================================


// =============================================================================
// ================================= TYPEDEFS ==================================
// =============================================================================


// =============================================================================
// =============================== ENUMERATIONS ================================
// =============================================================================

enum class EMenuId
	: int16_t
{
	Invalid = -1
	, ConsoleMenu
	, StartMenu
	, Count
};

// =============================================================================
// ================================= CONSTANTS =================================
// =============================================================================

namespace Constants
{
} // !namespace Constants

#endif // !APP_DEFINES_H_