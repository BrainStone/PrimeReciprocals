#pragma once

#include "math.hpp"

template <std::unsigned_integral T>
constexpr T pow_mod(T base, T exponent, T mod) {
	base %= mod;

	T result = 1;
	T tmp_base = base;

	while (exponent > 0) {
		if ((exponent & 1) == 1) {
			result = (result * tmp_base) % mod;
		}

		exponent >>= 1;
		tmp_base = (tmp_base * tmp_base) % mod;
	}

	return result;
}
