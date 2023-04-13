#ifndef UTILS_OTHERS_CRYPTO_H_
#define UTILS_OTHERS_CRYPTO_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <vector>

// Third-party includes

// Own includes

// Forward declarations

namespace Crypto
{
	void CaesarEncrypt(std::string& text, int32_t offset);
	void CaesarDecrypt(std::string& text, int32_t offset);

	void CaesarMovingEncrypt(std::string& text, int32_t offset, int32_t limit);
	void CaesarMovingDecrypt(std::string& text, int32_t offset, int32_t limit);

	std::vector<int32_t> CaesarRandomEncryptStoredOffsets(std::string& text, int32_t magicValue);
	//bool CaesarRandomEncryptHardcodedOffsets(std::string& text, const std::vector<int32_t>& offsets, int32_t magicValue);
	bool CaesarRandomDecrypt(std::string& text, const std::vector<int32_t>& offsets, int32_t magicValue);

	std::vector<int32_t> CaesarRandomEncryptWithFillingStoredOffsets(std::string& text, int32_t magicValue, int32_t fillingCount);
	//bool CaesarRandomEncryptWithFillingHardcodedOffsets(std::string& text, const std::vector<int32_t>& offsets, int32_t magicValue, int32_t fillingCount);
	bool CaesarRandomDecryptWithFilling(std::string& text, const std::vector<int32_t>& offsets, int32_t magicValue, int32_t fillingCount);

	void InvertBits(std::string& text);
} // !namespace Crypto

#endif // !UTILS_OTHERS_CRYPTO_H_