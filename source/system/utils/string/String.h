#pragma once

class String
{
public:
	String();
	String(const char* string);
	String(const std::string& string);

	~String();

	String(const String& other);
	String(String&& other);

	String& operator=(const String& other);
	String& operator=(String&& other);

	bool operator==(const String& other) const;

	void				Rehash();

public:
	std::string			m_String;
	Hash32				m_Hash;
};