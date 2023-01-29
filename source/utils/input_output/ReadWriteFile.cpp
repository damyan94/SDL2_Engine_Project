// Corresponding header
#include "utils/input_output/ReadWriteFile.h"

// C/C++ system includes
#include <iostream>
#include <fstream>
#include <locale>

// Third-party includes

// Own includes

// =============================================================================
int32_t ReadWriteFile::ReadFromFile(const std::string& fileName,
	std::vector<std::string>& readStrings)
{
	std::ifstream inStream(fileName, std::ios::in);
	// Error, unable to open file.
	AssertReturnIf(!inStream.is_open(), EXIT_FAILURE);

	std::string readLine;
	while (std::getline(inStream, readLine))
	{
		//The '#' symbol will indicate a commented line in the input file
		if (readLine[0] == '#' || readLine.size() <= 0)
		{
			continue;
		}
		readStrings.push_back(readLine);
	}

	inStream.close();

	return EXIT_SUCCESS;
}

// =============================================================================
int32_t ReadWriteFile::ReadFromFile(const std::string& fileName,
	std::vector<std::wstring>& readStrings)
{
	std::wifstream inStream(fileName, std::ios::in);
	inStream.imbue(std::locale("bg_BG.UTF-8"));
	// Error, unable to open file.
	AssertReturnIf(!inStream.is_open(), EXIT_FAILURE);

	std::wstring readLine;
	while (std::getline(inStream, readLine))
	{
		//The '#' symbol will indicate a commented line in the input file
		if (readLine[0] == '#' || readLine.size() <= 0)
		{
			continue;
		}
		readStrings.push_back(readLine);
	}

	inStream.close();

	return EXIT_SUCCESS;
}

// =============================================================================
int32_t ReadWriteFile::WriteToFile(const std::string& fileName,
	const std::string& writeString, WriteMode writeMode)
{
	std::ofstream outStream;

	switch (writeMode)
	{
	case WriteMode::OUT:
		outStream.open(fileName, std::ios::out);
		break;

	case WriteMode::APP:
		outStream.open(fileName, std::ios::app);
		break;

	default:
		break;
	}

	// Error, unable to open file.
	AssertReturnIf(!outStream.is_open(), EXIT_FAILURE);

	outStream << writeString;

	outStream.close();

	return EXIT_SUCCESS;
}

// =============================================================================
int32_t ReadWriteFile::WriteToFile(const std::string& fileName,
	const std::wstring& writeString, WriteMode writeMode)
{
	std::wofstream outStream;
	outStream.imbue(std::locale("bg_BG.UTF-8"));

	switch (writeMode)
	{
	case WriteMode::OUT:
		outStream.open(fileName, std::ios::out);
		break;

	case WriteMode::APP:
		outStream.open(fileName, std::ios::app);
		break;

	default:
		break;
	}

	// Error, unable to open file.
	AssertReturnIf(!outStream.is_open(), EXIT_FAILURE);

	outStream << writeString;

	outStream.close();

	return EXIT_SUCCESS;
}