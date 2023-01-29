#ifndef UTILS_OTHERS_CRYPTO_H_
#define UTILS_OTHERS_CRYPTO_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

// Forward declarations

namespace Crypto
{
	void CaesarEncrypt(std::wstring& text, int32_t offset);
	void CaesarDecrypt(std::wstring& text, int32_t offset);

	void CaesarMovingEncrypt(std::wstring& text, int32_t offset);
	void CaesarMovingDecrypt(std::wstring& text, int32_t offset);

	std::vector<int32_t> CaesarRandomEncryptStoredOffsets(std::wstring& text, int32_t magicValue);
	//bool CaesarRandomEncryptHardcodedOffsets(std::wstring& text, const std::vector<int32_t>& offsets, int32_t magicValue);
	bool CaesarRandomDecrypt(std::wstring& text, const std::vector<int32_t>& offsets, int32_t magicValue);


	std::vector<int32_t> CaesarRandomEncryptWithFillingStoredOffsets(std::wstring& text, int32_t magicValue, int32_t fillingCount);
	//bool CaesarRandomEncryptWithFillingHardcodedOffsets(std::wstring& text, const std::vector<int32_t>& offsets, int32_t magicValue, int32_t fillingCount);
	bool CaesarRandomDecryptWithFilling(std::wstring& text, const std::vector<int32_t>& offsets, int32_t magicValue, int32_t fillingCount);

	void InvertBits(std::wstring& text);
} // !namespace Crypto

#endif // !UTILS_OTHERS_CRYPTO_H_