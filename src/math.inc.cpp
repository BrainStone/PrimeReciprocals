#ifndef MATH_INC_CPP
#define MATH_INC_CPP

#include "math.hpp"

// Based on this StackOverflow answer: https://stackoverflow.com/a/20972369/1996022
template <std::unsigned_integral T>
constexpr T mul_mod(T factor1, T factor2, T mod) {
	factor1 %= mod;
	factor2 %= mod;

	const T quotient = mod / factor1;
	const T ratio = mod % factor1;

	const T partial_diff1 = factor1 * (factor2 % quotient);
	const T tmp = factor2 / quotient;
	const T partial_diff2 = (ratio >= quotient) ? mul_mod<T>(ratio, tmp, mod) : (ratio * tmp);

	if (partial_diff1 < partial_diff2)
		return partial_diff1 + (mod - partial_diff2);
	else
		return partial_diff1 - partial_diff2;
}

template <std::unsigned_integral T>
constexpr T pow_mod(T base, T exponent, T mod) {
	base %= mod;

	T result = 1;
	T tmp_base = base;

	while (exponent > 0) {
		if ((exponent & 1) == 1) {
			result = mul_mod<T>(result, tmp_base, mod);
		}

		exponent >>= 1;
		tmp_base = mul_mod<T>(tmp_base, tmp_base, mod);
	}

	return result;
}

#endif
