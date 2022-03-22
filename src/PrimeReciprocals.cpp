#include "PrimeReciprocals.hpp"

#include <iostream>
#include <limits>

#include "PrimeIterator.hpp"
#include "math.hpp"

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
}
