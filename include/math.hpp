#pragma once

#include <concepts>

template <std::unsigned_integral T>
constexpr T add_mod(T sum1, T sum2, T mod);
template <std::unsigned_integral T>
constexpr T add_mod_unsafe(T sum1, T sum2, T mod);

template <std::unsigned_integral T>
constexpr T mul_mod(T fac1, T fac2, T mod);
template <std::unsigned_integral T>
constexpr T mul_mod_unsafe(T fac1, T fac2, T mod);

template <std::unsigned_integral T>
constexpr T pow_mod(T base, T exp, T mod);
template <std::unsigned_integral T>
constexpr T pow_mod_unsafe(T base, T exp, T mod);

// Actual definitions here!
#include "math.inc.cpp"
