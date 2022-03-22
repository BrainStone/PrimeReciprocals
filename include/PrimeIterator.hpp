#pragma once

#include <concepts>
#include <vector>

template <std::unsigned_integral T>
class PrimeIterator;

template <std::unsigned_integral T>
class PrimeGenerator {
private:
	using container_type = std::vector<T>;

	typename container_type found_primes;
	T number_to_check;

public:
	using iterator_type = PrimeIterator<T>;

	PrimeGenerator();
	PrimeGenerator(const PrimeGenerator<T>& other) = default;
	PrimeGenerator(PrimeGenerator<T>&& other) = default;
	~PrimeGenerator() = default;

	PrimeGenerator<T>& operator=(const PrimeGenerator<T>& other) = default;
	PrimeGenerator<T>& operator=(PrimeGenerator<T>&& other) = default;

	iterator_type begin();

private:
	void generate_more();
	bool is_prime(T num);

	friend class PrimeIterator<T>;
};

template <std::unsigned_integral T>
class PrimeIterator {
private:
	using internal_iterator_type = typename PrimeGenerator<T>::container_type::const_iterator;

	PrimeGenerator<T>* generator;
	typename internal_iterator_type current_prime;

	PrimeIterator(PrimeGenerator<T>* generator);

public:
	using difference_type = typename internal_iterator_type::difference_type;
	using value_type = T;

	PrimeIterator() = default;
	PrimeIterator(const PrimeIterator<T>& other) = default;
	PrimeIterator(PrimeIterator<T>&& other) = default;
	~PrimeIterator() = default;

	PrimeIterator<T>& operator=(const PrimeIterator<T>& other) = default;
	PrimeIterator<T>& operator=(PrimeIterator<T>&& other) = default;

	bool operator==(const PrimeIterator<T>& other) const;

	T operator*() const;

	PrimeIterator<T>& operator++();
	PrimeIterator<T> operator++(int);

	PrimeIterator<T>& operator--();
	PrimeIterator<T> operator--(int);

	friend class PrimeGenerator<T>;
};

// Actual definitions here!
#include "PrimeIterator.inc.cpp"
