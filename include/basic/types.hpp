#pragma once

#include <cstdint>

#ifndef _INCLUDE_TYPES_HPP
#define _INCLUDE_TYPES_HPP


namespace media {

using uint8 = std::uint8_t;
using  int8 = std::int8_t;
using  byte = std::uint8_t;

using uint16 = std::uint16_t;
using  int16 = std::int16_t;

using uint32 = std::uint32_t;
using  int32 = std::int32_t;

using uint64 = std::uint64_t;
using  int64 = std::int64_t;

typedef struct _uint24{
    byte value[3];
} uint24;

}

#endif//_INCLUDE_TYPES_HPP

