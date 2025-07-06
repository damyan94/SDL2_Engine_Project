#pragma once

struct StringContainerConfig
{
	bool				Read(const StringVector& readStrings);

	std::unordered_map<ELanguage, StringVector>	StringContainerConfig;
};