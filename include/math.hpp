#pragma once

#include <concepts>

template <std::unsigned_integral T>
constexpr T mul_mod(T factor1, T factor2, T mod);

template <std::unsigned_integral T>
constexpr T pow_mod(T base, T exponent, T mod);


#include "math.inc.cpp"
