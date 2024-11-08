#ifndef UTILS_CONTAINERS_BINARYSTRUCT_H_
#define UTILS_CONTAINERS_BINARYSTRUCT_H_

class BinaryStruct
{
private:
	struct Entry
	{
		uint32_t m_Hash;
		uint32_t m_Size;
	};

public:
	BinaryStruct();
	BinaryStruct(const std::string& fileName);
	~BinaryStruct();

	bool UpdateFromFile(const std::string& fileName);

	template<typename T>
	bool Get(const String& string, T& outValue);

private:
	template<typename T>
	T* GetImplementation(const String& string);

public:
	uint8_t* m_Data;
};


// --- TEST ---

enum class DataType : uint8_t
{
	BinaryStruct = 1
	, Int = 2
};

////////////////////////////////////////////////////////////////////////////////
template<typename T>
bool BinaryStruct::Get(const String& string, T& outValue)
{
	T* ptr = GetImplementation<T>(string);
	ReturnIf(!ptr, false);

	outValue = *ptr;
	return true;
}

////////////////////////////////////////////////////////////////////////////////
template<>
inline bool BinaryStruct::Get<String>(const String& string, String& outValue)
{
	char* ptr = GetImplementation<char>(string);
	ReturnIf(!ptr, false);

	outValue = ptr;
	return true;
}

////////////////////////////////////////////////////////////////////////////////
template<>
inline bool BinaryStruct::Get<std::string>(const String& string, std::string& outValue)
{
	char* ptr = GetImplementation<char>(string);
	ReturnIf(!ptr, false);

	outValue = ptr;
	return true;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T>
T* BinaryStruct::GetImplementation(const String& string)
{
	// Set the pointer to the beginning of the data
	uint8_t* data = m_Data + sizeof(Entry);

	// Get the total size of the data
	uint32_t size = *(uint32_t*)(m_Data + sizeof(Entry::m_Hash));
	uint8_t* dataEnd = m_Data + size;

	while (true)
	{
		// Read entry data and advance the pointer by 8 bytes
		Entry entry = *(Entry*)(data);
		data += sizeof(entry);

		// Check if this is the data we are looking for and if so, return
		if (entry.m_Hash == string.m_Hash)
		{
			return (T*)(data);
		}

		// Break if we have reached the end of the binary struct
		BreakIf(data + entry.m_Size >= dataEnd);

		// Advance the pointer by the size of the stored data
		data += entry.m_Size;
	}

	return nullptr;
}

#endif // !UTILS_CONTAINERS_BINARYSTRUCT_H_