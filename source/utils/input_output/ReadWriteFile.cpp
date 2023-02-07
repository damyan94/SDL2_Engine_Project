// Corresponding header
#include "utils/input_output/ReadWriteFile.h"

// C/C++ system includes
#include <fstream>
#include <locale>

// Third-party includes

// Own includes

//TODO Refactor

// =============================================================================
bool ReadWriteFile::ReadFromFile(const std::string& fileName,
	std::vector<std::string>& readStrings)
{
	std::ifstream inStream(fileName, std::ios::in);
	AssertReturnIf(!inStream.is_open(), false, "Failed to open file.");

	std::string readLine;
	while (std::getline(inStream, readLine))
	{
		//The '#' symbol will indicate a commented line in the input file
		ContinueIf(readLine[0] == '#' || readLine.size() <= 0);

		readStrings.push_back(readLine);
	}

	inStream.close();

	return true;
}

// =============================================================================
bool ReadWriteFile::ReadFromFile(const std::string& fileName,
	std::vector<std::wstring>& readStrings)
{
	std::wifstream inStream(fileName, std::ios::in);
	inStream.imbue(std::locale("bg_BG.UTF-8"));
	AssertReturnIf(!inStream.is_open(), false, "Failed to open file.");

	std::wstring readLine;
	while (std::getline(inStream, readLine))
	{
		//The '#' symbol will indicate a commented line in the input file
		ContinueIf(readLine[0] == '#' || readLine.size() <= 0);

		readStrings.push_back(readLine);
	}

	inStream.close();

	return true;
}

// =============================================================================
bool ReadWriteFile::WriteToFile(const std::string& fileName,
	const std::string& writeString, EWriteMode writeMode)
{
	std::ofstream outStream;

	switch (writeMode)
	{
	case EWriteMode::Out:
		outStream.open(fileName, std::ios::out);
		break;

	case EWriteMode::App:
		outStream.open(fileName, std::ios::app);
		break;

	default:
		break;
	}

	AssertReturnIf(!outStream.is_open(), false, "Failed to open file.");

	outStream << writeString;

	outStream.close();

	return true;
}

// =============================================================================
bool ReadWriteFile::WriteToFile(const std::string& fileName,
	const std::wstring& writeString, EWriteMode writeMode)
{
	std::wofstream outStream;
	outStream.imbue(std::locale("bg_BG.UTF-8"));

	switch (writeMode)
	{
	case EWriteMode::Out:
		outStream.open(fileName, std::ios::out);
		break;

	case EWriteMode::App:
		outStream.open(fileName, std::ios::app);
		break;

	default:
		break;
	}

	AssertReturnIf(!outStream.is_open(), false, "Failed to open file.");

	outStream << writeString;

	outStream.close();

	return true;
}