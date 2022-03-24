#ifndef MATH_INC_CPP
#define MATH_INC_CPP

#include "math.hpp"

#include "PrimeIterator.hpp"

template <std::unsigned_integral T>
constexpr T add_mod(T sum1, T sum2, T mod) {
	sum1 %= mod;
	sum2 %= mod;

	return add_mod_unsafe<T>(sum1, sum2, mod);
}

template <std::unsigned_integral T>
constexpr T add_mod_unsafe(T sum1, T sum2, T mod) {
	const T room = (mod - 1) - sum1;

	if (sum2 <= room)
		return sum1 + sum2;
	else
		return sum2 - room - 1;
}

template <std::unsigned_integral T>
constexpr T mul_mod(T fac1, T fac2, T mod) {
	fac1 %= mod;
	fac2 %= mod;

	return mul_mod_unsafe<T>(fac1, fac2, mod);
}

// Based on this StackOverflow answer: https://stackoverflow.com/a/20972369/1996022
template <std::unsigned_integral T>
constexpr T mul_mod_unsafe(T fac1, T fac2, T mod) {
	const T quotient = mod / fac1;
	const T ratio = mod % fac1;

	const T partial_diff1 = fac1 * (fac2 % quotient);
	const T tmp = fac2 / quotient;
	const T partial_diff2 = (ratio >= quotient) ? mul_mod_unsafe<T>(ratio, tmp, mod) : (ratio * tmp);

	if (partial_diff1 < partial_diff2)
		return partial_diff1 + (mod - partial_diff2);
	else
		return partial_diff1 - partial_diff2;
}

// template <std::unsigned_integral T>
// constexpr T mul_mod_unsafe(T fac1, T fac2, T mod) {
//	if (fac2 > fac1) std::swap(fac1, fac2);
//
//	T result = 0;
//	T diff;
//
//	while (fac2 > 0) {
//		if ((fac2 & 1) == 1) {
//			result = add_mod_unsafe<T>(result, fac1, mod);
//		}
//
//		fac2 >>= 1;
//		diff = mod - fac1;
//
//		if (fac1 < diff) {
//			fac1 <<= 1;
//		} else {
//			fac1 -= diff;
//		}
//	}
//
//	return result;
// }

template <std::unsigned_integral T>
constexpr T pow_mod(T base, T exp, T mod) {
	base %= mod;

	return pow_mod_unsafe(base, exp, mod);
}

template <std::unsigned_integral T>
constexpr T pow_mod_unsafe(T base, T exp, T mod) {
	T result = 1;

	while (exp > 0) {
		if ((exp & 1) == 1) {
			result = mul_mod_unsafe<T>(result, base, mod);
		}

		exp >>= 1;
		base = mul_mod_unsafe<T>(base, base, mod);
	}

	return result;
}

template <std::integral T, std::unsigned_integral U>
constexpr T pown(T base, U exp) {
	T result = 1;

	while (exp > 0) {
		if ((exp & 1) == 1) {
			result *= base;
		}

		exp >>= 1;
		base *= base;
	}

	return result;
}

template <std::unsigned_integral T>
static PrimeGenerator<T> generator{};

template <std::unsigned_integral T>
bool is_prime(T num) {
	const T limit = static_cast<T>(std::sqrt(num));

	for (typename PrimeGenerator<T>::iterator_type it = generator<T>.begin(); *it <= limit; ++it) {
		if ((num % *it) == 0) return false;
	}

	return true;
}

template <std::unsigned_integral T>
std::map<T, std::size_t> prime_factors(T num) {
	std::map<T, size_t> output;

	for (typename PrimeGenerator<T>::iterator_type it = generator<T>.begin(); *it <= sqrt(num); ++it) {
		if ((num % *it) == 0) {
			num /= *it;

			output.emplace(*it, 1);

			while ((num % *it) == 0) {
				num /= *it;

				++output[*it];
			}
		}
	}

	if (num != 1) output.emplace(num, 1);

	return output;
}

template <std::unsigned_integral T>
std::set<T> all_divisors(T num) {
	std::map<T, size_t> pfactors = prime_factors<T>(num);
	std::set<T> output;

	size_t count = 0;
	size_t temp_count;
	T prod;

	do {
		temp_count = count;
		prod = 1;

		for (const std::map<T, size_t>::value_type& factor : pfactors) {
			if (temp_count == 0) break;

			prod *= pown<T, T>(factor.first, temp_count % (factor.second + 1));
			temp_count /= (factor.second + 1);
		}

		output.insert(prod);

		++count;
	} while (temp_count == 0);

	return output;
}

template <std::unsigned_integral T>
T count_period(T prime) {
	const T base = 10 % prime;

	for (T divisor : all_divisors<T>(prime - 1)) {
		if (pow_mod_unsafe<T>(base, divisor, prime) == 1) return divisor;
	}

	// Can't happen!
	return 0;
}

#endif
