#include "PrimeReciprocals.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>

#include "PrimeIterator.hpp"
#include "math.hpp"

int main() {
	std::uint64_t prime;
	std::uint64_t period;

	std::cout << std::fixed << std::setprecision(3) << std::setfill('0');

	while (true) {
		std::cin >> prime;

		if (!std::cin) break;

		auto start = std::chrono::steady_clock::now();

		period = count_period(prime);

		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start);

		std::cout << "The reciprocal of " << prime << " has a period of " << period << " digits. (took " << duration
		          << ")" << std::endl;
	}
}
