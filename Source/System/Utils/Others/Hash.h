#pragma once

typedef uint32_t Hash32;
typedef uint64_t Hash64;

namespace Utils
{
// Jenkins One At A Time hashing algorithm
Hash32 Hash(const std::string& str);
} // !namespace Utils