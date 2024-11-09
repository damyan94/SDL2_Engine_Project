#include "stdafx.h"

#include "System/Utils/Others/RandomNumberGenerator.h"

////////////////////////////////////////////////////////////////////////////////
RandomNumberGenerator::RandomNumberGenerator()
	: m_Number(time(nullptr))
	, m_Min(0)
	, m_Max(0)
{
}

////////////////////////////////////////////////////////////////////////////////
RandomNumberGenerator::RandomNumberGenerator(int32_t seed)
	: m_Number(seed)
	, m_Min(0)
	, m_Max(0)
{
}

////////////////////////////////////////////////////////////////////////////////
RandomNumberGenerator::~RandomNumberGenerator()
{
}

////////////////////////////////////////////////////////////////////////////////
void RandomNumberGenerator::SetSeed(int32_t seed)
{
	m_Number = seed;
}

////////////////////////////////////////////////////////////////////////////////
void RandomNumberGenerator::SetMin(int32_t min)
{
	m_Min = min;
}

////////////////////////////////////////////////////////////////////////////////
void RandomNumberGenerator::SetMax(int32_t max)
{
	m_Max = max;
}

////////////////////////////////////////////////////////////////////////////////
uint64_t RandomNumberGenerator::GenerateUInt64()
{
	return GenerateUInt64(m_Min, m_Max);
}

////////////////////////////////////////////////////////////////////////////////
int64_t RandomNumberGenerator::GenerateInt64()
{
	return GenerateInt64(m_Min, m_Max);
}

////////////////////////////////////////////////////////////////////////////////
double RandomNumberGenerator::GenerateDouble()
{
	return GenerateDouble((double)m_Min, (double)m_Max);
}

////////////////////////////////////////////////////////////////////////////////
uint64_t RandomNumberGenerator::GenerateUInt64(uint64_t min, uint64_t max)
{
	ReturnIf(max - min == 0, 0);
	return min + Lehmer64() % (max - min);
}

////////////////////////////////////////////////////////////////////////////////
int64_t RandomNumberGenerator::GenerateInt64(int64_t min, int64_t max)
{
	ReturnIf(max - min == 0, 0);
	return min + Lehmer64() % (max - min);
}

////////////////////////////////////////////////////////////////////////////////
double RandomNumberGenerator::GenerateDouble(double min, double max)
{
	ReturnIf((max - min) == 0, 0);
	double fraction = (double)GenerateUInt64(1000000000000000, 9999999999999999)
		/ 10000000000000000;

	return min + fraction * (max - min);
}

////////////////////////////////////////////////////////////////////////////////
uint64_t RandomNumberGenerator::Lehmer64()
{
	m_Number += 0xE120FC15;
	uint64_t tmp;
	
	tmp = m_Number * 0x4A39B70D;
	uint64_t m1 = (tmp >> 32) ^ tmp;
	
	tmp = m1 * 0x12FAD5C9;
	uint64_t m2 = (tmp >> 32) ^ tmp;
	
	return m2;
}