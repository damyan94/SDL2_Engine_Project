// Corresponding header
#include "utils/string/String.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
String::String()
	: m_Hash(0)
{
}

// =============================================================================
String::String(const std::string& string)
	: m_String(string)
	, m_Hash(0)
{
	Rehash();
}

// =============================================================================
String::~String()
{
}

// =============================================================================
bool String::operator==(const String& other)
{
	return m_Hash == other.m_Hash;
}

// =============================================================================
void String::Rehash()
{
	m_Hash = Utils::JenkinsOneAtATime(m_String);
}