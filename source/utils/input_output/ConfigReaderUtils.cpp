// Corresponding header
#include "utils/input_output/ConfigReaderUtils.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

/**
* Brief Description
* 
* 1. The info is extracted from the file directly as string, no optimizations.
* 2. We walk the source string that contains our value, usually the read line.
* 3. Once we find it, we read from the position after the '=' sign until we reach
* an end condition.
* 4. These conditions are specific to the data read:
* 4.1. Single value - break when ';' character(RecordSeparator) is reached;
* 4.2. Value array - stop reading single value when ','(ValuesSeparator) is reached,
* then continue reading a new value, stop reading in the array when ';' character
* (RecordSeparator) is reached;
* 4.3. String - chech if string is formatted properly (enclosed in '"' characters
* (StringWrapper)), ignore StringWrapper characters preceded by '\\' character
* (StringWrapperCancelator);
* 4.4. String array - 
*/

namespace Utils
{
static constexpr char RecordSeparator			= ';';
static constexpr char ValuesSeparator			= ',';
static constexpr char DoubleQuote				= '"';
static constexpr char Backslash					= '\\';
static constexpr char NewLine					= 'n';
static constexpr char Tab						= 't';

// =============================================================================
int32_t ReadInt(const std::string& source, const std::string& str)
{
	int32_t result = -1;
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string inside the source string: " + str);

	const size_t startPos = strStartPos + str.size() + 1;
	std::string readValue;
	for (size_t i = startPos; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		readValue += currChar;
	}

	try
	{
		result = std::stoi(readValue);
	}
	catch(const std::exception& e)
	{
		AssertReturnIf(true, result, "Exception thrown: " + std::string(e.what()));
	}

	return result;
}

// =============================================================================
std::vector<int32_t> ReadIntArray(const std::string& source, const std::string& str, size_t size)
{
	std::vector<int32_t> result;
	result.reserve(size);
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string inside the source string: " + str);

	const size_t startPos = strStartPos + str.size() + 1;
	std::string readValue;
	for (size_t i = startPos; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		if (currChar == RecordSeparator || (currChar == ValuesSeparator || i >= source.size() - 1))
		{
			try
			{
				result.emplace_back(std::stoi(readValue));
			}
			catch (const std::exception& e)
			{
				AssertReturnIf(true, result, "Exception thrown: " + std::string(e.what()));
			}

			BreakIf(currChar == RecordSeparator);

			readValue.clear();
			continue;
		}

		if (currChar != ValuesSeparator && i <= source.size() - 1)
		{
			readValue += currChar;
		}
	}

	return result;
}

// =============================================================================
double ReadDouble(const std::string& source, const std::string& str)
{
	double result = -1;
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string inside the source string: " + str);

	const size_t startPos = strStartPos + str.size() + 1;
	std::string readValue;
	for (size_t i = startPos; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		readValue += currChar;
	}

	try
	{
		result = std::stod(readValue);
	}
	catch (const std::exception& e)
	{
		AssertReturnIf(true, result, "Exception thrown: " + std::string(e.what()));
	}

	return result;
}

// =============================================================================
std::vector<double> ReadDoubleArray(const std::string& source, const std::string& str, size_t size)
{
	std::vector<double> result;
	result.reserve(size);
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string inside the source string: " + str);

	const size_t startPos = strStartPos + str.size() + 1;
	std::string readValue;
	for (size_t i = startPos; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		if (currChar == RecordSeparator || (currChar == ValuesSeparator || i >= source.size() - 1))
		{
			try
			{
				result.emplace_back(std::stod(readValue));
			}
			catch (const std::exception& e)
			{
				AssertReturnIf(true, result, "Exception thrown: " + std::string(e.what()));
			}

			BreakIf(currChar == RecordSeparator);

			readValue.clear();
			continue;
		}

		if (currChar != ValuesSeparator && i <= source.size() - 1)
		{
			readValue += currChar;
		}
	}

	return result;
}

// =============================================================================
std::string ReadString(const std::string& source, const std::string& str)
{
	std::string result;
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string inside the source string: " + str);

	const size_t startPos = strStartPos + str.size() + 1;
	AssertReturnIf(source[startPos] != DoubleQuote, result,
		"Incorrectly formated string, missing opening quote. String name: " + str);

	bool isInsideStringWrapperCharacters = false;
	bool backslashActive = false;
	std::string readValue;
	for (size_t i = startPos; i < source.size(); i++)
	{
		auto currChar = source[i];

		if (currChar == RecordSeparator && !isInsideStringWrapperCharacters)
		{
			break;
		}

		if (currChar == DoubleQuote && !backslashActive)
		{
			isInsideStringWrapperCharacters = !isInsideStringWrapperCharacters;
			continue;
		}

		if (currChar == Backslash && isInsideStringWrapperCharacters)
		{
			backslashActive = true;
			continue;
		}

		if (backslashActive)
		{
			switch (currChar)
			{
			case NewLine:
				currChar = '\n';
				break;

			case Tab:
				currChar = '\t';
				break;

			default:
				break;
			}

			backslashActive = false;
		}

		readValue += currChar;
	}
	result = std::move(readValue);

	return result;
}

// =============================================================================
std::vector<std::string> ReadStringArray(const std::string& source, const std::string& str, size_t size)
{
	std::vector<std::string> result;
	result.reserve(size * 32);
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string inside the source string: " + str);

	const size_t startPos = strStartPos + str.size() + 1;
	AssertReturnIf(source[startPos] != DoubleQuote, result,
		"Incorrectly formated string, missing opening quote. String name: " + str);

	bool isInsideStringWrapperCharacters = false;
	bool backslashActive = false;
	std::string readValue;
	for (size_t i = startPos; i < source.size(); i++)
	{
		auto currChar = source[i];

		BreakIf(currChar == RecordSeparator && !isInsideStringWrapperCharacters);

		if (currChar == ValuesSeparator && !isInsideStringWrapperCharacters)
		{
			result.emplace_back(readValue);
			readValue.clear();
			continue;
		}

		if (currChar == DoubleQuote && !backslashActive)
		{
			isInsideStringWrapperCharacters = !isInsideStringWrapperCharacters;
			continue;
		}

		if (currChar == Backslash && isInsideStringWrapperCharacters)
		{
			backslashActive = true;
			continue;
		}

		if (backslashActive)
		{
			switch (currChar)
			{
			case NewLine:
				currChar = '\n';
				break;

			case Tab:
				currChar = '\t';
				break;

			default:
				break;
			}

			backslashActive = false;
		}

		readValue += currChar;
	}
	result.emplace_back(readValue);

	return result;
}

// =============================================================================
String ReadStringHashed(const std::string& source, const std::string& str)
{
	String result(ReadString(source, str));

	return result;
}

// =============================================================================
std::vector<String> ReadStringArrayHashed(const std::string& source, const std::string& str, size_t size)
{
	std::vector<String> result;
	auto unhashedStrings = ReadStringArray(source, str, size);
	result.reserve(unhashedStrings.size() * (32 + sizeof(Hash32)));

	for (auto&& unhashedString : unhashedStrings)
	{
		result.push_back(String(std::move(unhashedString)));
	}

	return result;
}
} // !namespace Utils