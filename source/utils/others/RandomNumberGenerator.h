#ifndef UTILS_OTHERS_RANDOMNUMBERGENERATOR_H_
#define UTILS_OTHERS_RANDOMNUMBERGENERATOR_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

class RandomNumberGenerator
{
public:
	RandomNumberGenerator();
	RandomNumberGenerator(int32_t seed);

	~RandomNumberGenerator();

	void				SetSeed(int32_t seed);
	void				SetMin(int32_t min);
	void				SetMax(int32_t max);

	uint64_t			GenerateUInt64();
	int64_t				GenerateInt64();
	double				GenerateDouble();

	uint64_t			GenerateUInt64(uint64_t min, uint64_t max);
	int64_t				GenerateInt64(int64_t min, int64_t max);
	double				GenerateDouble(double min, double max);

private:
	uint64_t			Lehmer64();

private:
	uint64_t			m_Number;
	uint64_t			m_Min;
	uint64_t			m_Max;
};

#endif // !UTILS_OTHERS_RANDOMNUMBERGENERATOR_H_