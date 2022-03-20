#pragma once

#include <concepts>
#include <cstdint>

template <std::unsigned_integral T>
constexpr T pow_mod(T base, T exponent, T mod);


#include "math.inc.cpp"
