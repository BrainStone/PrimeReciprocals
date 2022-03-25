#pragma once

#include <concepts>
#include <map>
#include <set>

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

template <std::integral T, std::unsigned_integral U>
constexpr T pown(T base, U exp);

template <std::unsigned_integral T>
bool is_prime(T num);

template <std::unsigned_integral T>
std::map<T, std::size_t> prime_factors(T num);

template <std::unsigned_integral T>
std::set<T> all_divisors(T num);

template <std::unsigned_integral T>
T make_coprime(T num, T other_num);

template <std::unsigned_integral T>
T totient(T num);

template <std::unsigned_integral T>
T count_period(T num);

// Actual definitions here!
#include "math.inc.cpp"
