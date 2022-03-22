#ifndef PRIME_ITERATOR_INC_CPP
#define PRIME_ITERATOR_INC_CPP

#include "PrimeIterator.hpp"

#include <cmath>

// PrimeGenerator
template <std::unsigned_integral T>
PrimeGenerator<T>::PrimeGenerator() : found_primes({2, 3, 5, 7}), last_checked_number(5) {}

template <std::unsigned_integral T>
typename PrimeGenerator<T>::iterator PrimeGenerator<T>::begin() {
	return PrimeIterator<T>(this);
}

template <std::unsigned_integral T>
void PrimeGenerator<T>::generate_more() {
	bool no_prime_found = true;

	while (no_prime_found) {
		last_checked_number += 6;

		if (is_prime(last_checked_number)) {
			found_primes.push_back(last_checked_number);
			no_prime_found = false;
		}

		if (is_prime(last_checked_number + 2)) {
			found_primes.push_back(last_checked_number + 2);
			no_prime_found = false;
		}
	}
}

template <std::unsigned_integral T>
bool PrimeGenerator<T>::is_prime(T num) {
	const T limit = static_cast<T>(std::sqrt(num));

	for (typename std::list<T>::const_iterator it = found_primes.cbegin(); *it <= limit; ++it) {
		if ((num % *it) == 0) return false;
	}

	return true;
}

// PrimeIterator
template <std::unsigned_integral T>
PrimeIterator<T>::PrimeIterator(PrimeGenerator<T>* generator)
    : generator(generator), current_prime(generator->found_primes.cbegin()) {}

template <std::unsigned_integral T>
bool PrimeIterator<T>::operator==(const PrimeIterator<T>& other) const {
	return (&this->generator == &other.generator) && (this->current_prime == other.current_prime);
}

template <std::unsigned_integral T>
T PrimeIterator<T>::operator*() const {
	return *current_prime;
}

template <std::unsigned_integral T>
PrimeIterator<T>& PrimeIterator<T>::operator++() {
	++current_prime;

	if (current_prime == generator->found_primes.cend()) {
		--current_prime;
		generator->generate_more();
		++current_prime;
	}

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
