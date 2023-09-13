#include "stdafx.h"

#include "system/utils/string/String.h"

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
	m_Hash = Utils::Hash(m_String);
}