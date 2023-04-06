#ifndef UTILS_STRING_STRING_H_
#define UTILS_STRING_STRING_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "utils/others/Hash.h"

// Forward declarations

class String
{
public:
	String();
	String(const std::string& string);

	~String();

	bool operator==(const String& other);

	void				Rehash();

public:
	std::string			m_String;
	Hash32				m_Hash;
};

#endif // !UTILS_STRING_STRING_H_