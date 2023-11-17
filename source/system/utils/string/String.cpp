#include "stdafx.h"

#include "system/utils/string/String.h"

// =============================================================================
String::String()
	: m_Hash(0)
{
}

// =============================================================================
String::String(const char* string)
	: m_String(string)
	, m_Hash(0)
{
	Rehash();
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
String::String(const String& other)
	: m_String(other.m_String)
	, m_Hash(other.m_Hash)
{
}

// =============================================================================
String::String(String&& other)
	: m_String(std::move(other.m_String))
	, m_Hash(other.m_Hash)
{
}

// =============================================================================
String& String::operator=(const String& other)
{
	m_String = other.m_String;
	m_Hash = other.m_Hash;

	return *this;
}

// =============================================================================
String& String::operator=(String&& other)
{
	m_String = std::move(other.m_String);
	m_Hash = other.m_Hash;

	return *this;
}

// =============================================================================
bool String::operator==(const String& other) const
{
	return m_Hash == other.m_Hash;
}

// =============================================================================
void String::Rehash()
{
	m_Hash = Utils::Hash(m_String);
}