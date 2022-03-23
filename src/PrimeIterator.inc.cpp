#ifndef PRIME_ITERATOR_INC_CPP
#define PRIME_ITERATOR_INC_CPP

#include "PrimeIterator.hpp"

#include <cmath>

// PrimeGenerator
template <std::unsigned_integral T>
PrimeGenerator<T>::PrimeGenerator() : found_primes({2, 3}), number_to_check(5) {}

template <std::unsigned_integral T>
typename PrimeGenerator<T>::iterator_type PrimeGenerator<T>::begin() {
	return PrimeIterator<T>(this);
}

template <std::unsigned_integral T>
void PrimeGenerator<T>::generate_more() {
	bool no_prime_found = true;

	while (no_prime_found) {
		if (is_prime(number_to_check)) {
			found_primes.push_back(number_to_check);
			no_prime_found = false;
		}

		number_to_check += 2;

		if (is_prime(number_to_check)) {
			found_primes.push_back(number_to_check);
			no_prime_found = false;
		}

		number_to_check += 4;
	}
}

template <std::unsigned_integral T>
bool PrimeGenerator<T>::is_prime(T num) {
	const T limit = static_cast<T>(std::sqrt(num));

	for (typename container_type::const_iterator it = found_primes.cbegin(); *it <= limit; ++it) {
		if ((num % *it) == 0) return false;
	}

	return true;
}

// PrimeIterator
template <std::unsigned_integral T>
PrimeIterator<T>::PrimeIterator(PrimeGenerator<T>* generator)
    : generator(generator), current_prime(0) {}

template <std::unsigned_integral T>
bool PrimeIterator<T>::operator==(const PrimeIterator<T>& other) const {
	return (&this->generator == &other.generator) && (this->current_prime == other.current_prime);
}

template <std::unsigned_integral T>
T PrimeIterator<T>::operator*() const {
	return generator->found_primes[current_prime];
}

template <std::unsigned_integral T>
PrimeIterator<T>& PrimeIterator<T>::operator++() {
	if ((current_prime + 1) >= generator->found_primes.size()) {
		generator->generate_more();
	}

	++current_prime;

	return *this;
}

template <std::unsigned_integral T>
PrimeIterator<T> PrimeIterator<T>::operator++(int) {
	PrimeIterator<T> copy(*this);
	++*this;
	return copy;
}

template <std::unsigned_integral T>
PrimeIterator<T>& PrimeIterator<T>::operator--() {
	--current_prime;

	return *this;
}

template <std::unsigned_integral T>
PrimeIterator<T> PrimeIterator<T>::operator--(int) {
	PrimeIterator<T> copy(*this);
	--*this;
	return copy;
}

#endif
