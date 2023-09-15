#ifndef UTILS_STRING_STRING_H_
#define UTILS_STRING_STRING_H_

class String
{
public:
	String();
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

#endif // !UTILS_STRING_STRING_H_