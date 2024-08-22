
#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

const char* Span::maxSizeReached::what() const throw()
{
	return ("Cannot add more elements to span, max size reached");
}


const char* Span::spanTooSmall::what() const throw()
{
	return ("Span too small to perform span operations on");
};

Span::Span() {}

Span::Span(unsigned int N)
{
	try
	{
		this->max = N;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Span& Span::operator=(const Span& other) 
{
	if (this != &other)
	{
		this->numbers = other.numbers;
		this->max = other.max;
	}
	return (*this);
}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span() {}

void Span::addNumber(int x)
{
	if ((numbers.size() + 1) <= max)
		numbers.push_back(x);
	else
		throw(maxSizeReached());
}

int Span::shortestSpan()
{
	if (max <= 1 || numbers.size() <= 1)
		throw(spanTooSmall());
	std::sort(numbers.begin(), numbers.end());
	int min_span = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator iter = numbers.begin(); iter != numbers.end() - 1; iter++) {
		int	diff = *(iter + 1) - *iter;
		if (diff < min_span)
			min_span = diff;
	}
	return (min_span);
}

int Span::longestSpan()
{
	if (max <= 1 || numbers.size() <= 1)
		throw(spanTooSmall());

	std::vector<int>::iterator min_int;
	std::vector<int>::iterator max_int;

	min_int = std::min_element(numbers.begin(), numbers.end());
	max_int = std::max_element(numbers.begin(), numbers.end());

	return (*max_int - *min_int);
}


void	Span::fill(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator iter = start; iter != end; iter++) {
		try
		{
			this->addNumber(*iter);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

void	Span::printSpan()
{
	for (std::vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}
