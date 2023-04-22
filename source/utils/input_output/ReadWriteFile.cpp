// Corresponding header
#include "utils/input_output/ReadWriteFile.h"

// C/C++ system includes
#include <fstream>

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

namespace ReadWriteFile
{
// =============================================================================
bool ReadFromFile(const std::string& fileName, std::string& readString)
{
	std::ifstream inStream(fileName, std::ios::in);
	AssertReturnIf(!inStream.is_open(), false, "Failed to open file: " + fileName);

	readString.clear();

	std::string readLine;
	while (std::getline(inStream, readLine))
	{
		//The '#' symbol will indicate a commented line in the input file
		ContinueIf(readLine[0] == '#' || readLine.size() <= 0);

		readString += readLine;
	}

	inStream.close();

	return true;
}

// =============================================================================
bool ReadFromFile(const std::string& fileName, std::vector<std::string>& readStrings)
{
	std::ifstream inStream(fileName, std::ios::in);
	AssertReturnIf(!inStream.is_open(), false, "Failed to open file: " + fileName);

	readStrings.clear();

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
bool WriteToFile(const std::string& fileName,
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

	AssertReturnIf(!outStream.is_open(), false, "Failed to open file: " + fileName);

	outStream << writeString;

	outStream.close();

	return true;
}
} // !namespace ReadWriteFile