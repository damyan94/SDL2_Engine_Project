#ifndef MANAGERS_DEFINES_H_
#define MANAGERS_DEFINES_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

// =============================================================================
// ================================= DEFINES ===================================
// =============================================================================


// =============================================================================
// ================================= TYPEDEFS ==================================
// =============================================================================


// =============================================================================
// =============================== ENUMERATIONS ================================
// =============================================================================

enum class EManagerType
	: int16_t
{
	Invalid = -1
	, AssetManager
	, DrawManager
	, TimerManager
	, Count
};

// =============================================================================
// ================================= CONSTANTS =================================
// =============================================================================

namespace ManagersConstants
{

} // !namespace ManagersConstants

#endif // !MANAGERS_DEFINES_H_