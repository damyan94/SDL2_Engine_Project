#ifndef UTILS_STRING_STRING_H_
#define UTILS_STRING_STRING_H_

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