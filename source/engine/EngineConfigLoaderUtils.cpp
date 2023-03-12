// Corresponding header
#include "engine/EngineConfigLoaderUtils.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadabilityDefines.h"

namespace Utils
{
static constexpr char RecordSeparator = ' ';
static constexpr char ValuesSeparator = ',';

// =============================================================================
int32_t ReadInt(const std::string& source, const std::string& str)
{
	int32_t result = -1;
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string in the source string: " + str);

	const size_t separatorPos = strStartPos + str.size();
	std::string readValue;
	for (size_t i = separatorPos + 1; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		readValue += currChar;
	}
	result = std::stoi(readValue);

	return result;
}

// =============================================================================
std::vector<int32_t> ReadIntArray(const std::string& source, const std::string& str, size_t size)
{
	std::vector<int32_t> result;
	result.reserve(size);
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string in the source string: %s" + str);

	const size_t separatorPos = strStartPos + str.size();
	std::string readValue;
	for (size_t i = separatorPos + 1; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		if (currChar == ValuesSeparator || i >= source.size() - 1)
		{
			result.emplace_back(std::stoi(readValue));
			readValue.clear();
			continue;
		}
		readValue += currChar;
	}

	return result;
}

// =============================================================================
double ReadDouble(const std::string& source, const std::string& str)
{
	double result = -1;
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string in the source string: " + str);

	const size_t separatorPos = strStartPos + str.size();
	std::string readValue;
	for (size_t i = separatorPos + 1; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		readValue += currChar;
	}
	result = std::stoi(readValue);

	return result;
}

// =============================================================================
std::vector<double> ReadDoubleArray(const std::string& source, const std::string& str, size_t size)
{
	std::vector<double> result;
	result.reserve(size);
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string in the source string: " + str);

	const size_t separatorPos = strStartPos + str.size();
	std::string readValue;
	for (size_t i = separatorPos + 1; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		if (currChar == ValuesSeparator || i >= source.size() - 1)
		{
			result.emplace_back(std::stoi(readValue));
			readValue.clear();
			continue;
		}
		readValue += currChar;
	}

	return result;
}

// =============================================================================
std::string ReadString(const std::string& source, const std::string& str)
{
	std::string result;
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string in the source string: " + str);

	const size_t separatorPos = strStartPos + str.size();
	std::string readValue;
	for (size_t i = separatorPos + 1; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		readValue += currChar;
	}
	result = readValue;

	return result;
}

// =============================================================================
std::vector<std::string> ReadStringArray(const std::string& source, const std::string& str, size_t size)
{
	std::vector<std::string> result;
	result.reserve(size);
	const size_t strStartPos = source.find(str);
	AssertReturnIf(strStartPos == std::string::npos, result,
		"Could not find the specified string in the source string: " + str);

	const size_t separatorPos = strStartPos + str.size();
	std::string readValue;
	for (size_t i = separatorPos + 1; i < source.size(); i++)
	{
		const auto& currChar = source[i];
		BreakIf(currChar == RecordSeparator);
		if (currChar == ValuesSeparator || i >= source.size() - 1)
		{
			result.emplace_back(readValue);
			readValue.clear();
			continue;
		}
		readValue += currChar;
	}

	return result;
}
} // !namespace Utils