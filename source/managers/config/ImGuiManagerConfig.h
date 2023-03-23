#ifndef MANAGERS_CONFIG_IMGUIMANAGERCONFIG_H_
#define MANAGERS_CONFIG_IMGUIMANAGERCONFIG_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
enum class EImGuiStyle : int16_t;

struct ImGuiManagerConfig
{
	bool				Read();

	EImGuiStyle			m_ImGuiStyle;
};

#endif // !MANAGERS_CONFIG_IMGUIMANAGERCONFIG_H_