/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef DEFINES_TYPES_HPP
#define DEFINES_TYPES_HPP

// Define datatypes
#include <cstdint>

// Boolean type
#ifndef boolean
    typedef bool          boolean;
#endif

// Float types
#ifndef float32
    typedef float         float32;
#endif
#ifndef float64
    typedef double        float64;
#endif
#ifndef float128
    typedef long double   float128;
#endif

// Integer types
#ifndef uint8
    typedef std::uint8_t  uint8;
#endif
#ifndef uint16
    typedef std::uint16_t uint16;
#endif
#ifndef uint32
    typedef std::uint32_t uint32;
#endif
#ifndef uint64
    typedef std::uint64_t uint64;
#endif

#ifndef int8
    typedef std::int8_t   int8;
#endif
#ifndef int16
    typedef std::int16_t  int16;
#endif
#ifndef int32
    typedef std::int32_t  int32;
#endif
#ifndef int64
    typedef std::int64_t  int64;
#endif

#endif // DEFINES_TYPES_HPP
