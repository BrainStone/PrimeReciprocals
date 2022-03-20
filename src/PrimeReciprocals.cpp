#include "PrimeReciprocals.hpp"

int main() {
	constexpr auto res = pow_mod(10U, 34U, 103U);

	std::cout << "10 ^ 34 mod 103 = " << res << std::endl;
}
