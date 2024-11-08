#include "stdafx.h"

#include "System/Utils/Containers/BinaryStruct.h"

////////////////////////////////////////////////////////////////////////////////
BinaryStruct::BinaryStruct()
	: m_Data(nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
BinaryStruct::BinaryStruct(const std::string& fileName)
	: m_Data(nullptr)
{
	UpdateFromFile(fileName);
}

////////////////////////////////////////////////////////////////////////////////
BinaryStruct::~BinaryStruct()
{
	SafeDelete(m_Data);
}

////////////////////////////////////////////////////////////////////////////////
bool BinaryStruct::UpdateFromFile(const std::string& fileName)
{
	SafeDelete(m_Data);

	std::ifstream in("binary_test.bin", std::ios::in | std::ios::binary | std::ios::ate);
	const int32_t dataSize = in.tellg();

	m_Data = new uint8_t[dataSize]{ '\0' };
	in.seekg(0);
	in.read(reinterpret_cast<char*>(m_Data), dataSize);

	in.close();

	AssertReturnIf(!m_Data && ("Failed to read data from file: " + fileName).c_str(), false);

	return true;
}