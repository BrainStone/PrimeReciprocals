#include "PrimeReciprocals.hpp"

#include <iostream>
#include <limits>

#include "PrimeIterator.hpp"
#include "math.hpp"

void print_prime_factors(std::uint64_t num) {
	bool print_star = false;

	for (const auto& factor : prime_factors(num)) {
		if (print_star)
			std::cout << " * ";
		else
			print_star = true;

		std::cout << factor.first << "^" << factor.second;
	}

	std::cout << std::endl;
}

int main() {
	constexpr auto res = pow_mod(10U, 34U, 103U);
	constexpr auto res2 =
	    pow_mod(std::numeric_limits<std::uint32_t>::max() - 3, std::numeric_limits<std::uint32_t>::max() - 4,
	            std::numeric_limits<std::uint32_t>::max() - 2);
	constexpr auto res3 =
	    mul_mod(std::numeric_limits<std::uint32_t>::max() - 3, std::numeric_limits<std::uint32_t>::max() - 4,
	            std::numeric_limits<std::uint32_t>::max() - 2);

	std::cout << "10 ^ 34 mod 103 = " << res << std::endl;

	PrimeGenerator<std::uint64_t> gen;
	std::bidirectional_iterator auto test = gen.begin();

	for (typename PrimeGenerator<std::uint64_t>::iterator it = gen.begin(); *it < 1000; ++it) {
		std::cout << *it << '\n';
	}

	std::cout.flush();

	print_prime_factors(73014444032);
	print_prime_factors(4294967296);
	print_prime_factors(std::numeric_limits<std::uint32_t>::max() - 3);
	print_prime_factors(std::numeric_limits<std::uint32_t>::max() - 4);
	print_prime_factors(std::numeric_limits<std::uint64_t>::max() - 3);
	print_prime_factors(std::numeric_limits<std::uint64_t>::max() - 4);
	print_prime_factors(4449874897498964);
}
