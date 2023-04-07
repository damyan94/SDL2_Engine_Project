// Corresponding header
#include "utils/others/Hash.h"

// C/C++ system includes
#include <functional>

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

namespace Utils
{
// =============================================================================
Hash32 Hash(const std::string& str)
{
    Hash32 hash = 0;
    size_t length = str.size();
    ReturnIf(length <= 0, hash);

    for (size_t i = 0; i < length; i++)
    {
        hash += str[i];
        hash += hash << 10;
        hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;

    return hash;
}
} // !namespace Utils