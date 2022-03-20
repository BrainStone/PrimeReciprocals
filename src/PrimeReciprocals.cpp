#include "PrimeReciprocals.hpp"

#include <limits>

int main() {
	constexpr auto res = pow_mod(10U, 34U, 103U);
	constexpr auto res2 =
	    pow_mod(std::numeric_limits<std::uint32_t>::max() - 3, std::numeric_limits<std::uint32_t>::max() - 4,
	            std::numeric_limits<std::uint32_t>::max() - 2);

	std::cout << "10 ^ 34 mod 103 = " << res << std::endl;
}
