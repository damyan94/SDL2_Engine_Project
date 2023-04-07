#ifndef UTILS_OTHERS_HASH_H_
#define UTILS_OTHERS_HASH_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes

// Forward declarations

typedef uint32_t Hash32;
typedef uint64_t Hash64;

namespace Utils
{
// Jenkins One At A Time hashing algorithm
Hash32 Hash(const std::string& str);
} // !namespace Utils

#endif // !UTILS_OTHERS_HASH_H_