#pragma once

#include <concepts>
#include <list>

template <std::unsigned_integral T>
class PrimeIterator;

template <std::unsigned_integral T>
class PrimeGenerator {
private:
	std::list<T> found_primes;
	T last_checked_number;

public:
	using iterator = PrimeIterator<T>;

	PrimeGenerator();
	PrimeGenerator(const PrimeGenerator<T>& other) = default;
	PrimeGenerator(PrimeGenerator<T>&& other) = default;
	~PrimeGenerator() = default;

	PrimeGenerator<T>& operator=(const PrimeGenerator<T>& other) = default;
	PrimeGenerator<T>& operator=(PrimeGenerator<T>&& other) = default;

	iterator begin();

private:
	void generate_more();
	bool is_prime(T num);

	friend class PrimeIterator<T>;
};

template <std::unsigned_integral T>
class PrimeIterator {
private:
	PrimeGenerator<T>* generator;
	std::list<T>::const_iterator current_prime;

	PrimeIterator(PrimeGenerator<T>* generator);

public:
	using difference_type = std::list<T>::const_iterator::difference_type;
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
