// Corresponding header
#include "utils/others/RandomNumberGenerator.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// =============================================================================
uint64_t RandomNumberGenerator::Lehmer64(uint64_t seed)
{
	seed += 0xe120fc15;
	uint64_t tmp;

	tmp = seed * 0x4a39b70d;
	uint64_t m1 = (tmp >> 32) ^ tmp;

	tmp = m1 * 0x12fad5c9;
	uint64_t m2 = (tmp >> 32) ^ tmp;

	return m2;
}