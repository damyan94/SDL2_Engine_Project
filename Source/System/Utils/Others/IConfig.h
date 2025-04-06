#pragma once

namespace std
{
}

struct IConfig
{
	virtual ~IConfig() = default;

	virtual bool Parse(const std::string& line)
	{
		return false;
	}

	virtual bool Parse(const std::vector<std::string>& lines)
	{
		return false;
	}
};