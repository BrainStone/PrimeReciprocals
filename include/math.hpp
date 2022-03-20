#pragma once

#include <concepts>

template <std::unsigned_integral T>
constexpr T pow_mod(T base, T exponent, T mod);


#include "math.inc.cpp"
