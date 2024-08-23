
#include "Span.hpp"
#include <iostream>

const char* Span::maxSizeReached::what() const throw()
{
	return ("Cannot add more elements to span, max size reached");
}


const char* Span::spanTooSmall::what() const throw()
{
	return ("Span too small to perform span operations on");
};

Span::Span() {}

Span::Span(unsigned int N) : max(N) {}

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

/*
	This (iter + 1) to access the next element in the container 
	only works with vectors because its elements are stored in a 
	contiguous fashion in terms of memory. But with other containers 
	like lists, stacks, deques, etc. the memory is arranged sporadically 
	and the link between the elements occurs via pointers.

	We have to sort them first because when we sort them like this:
		3, 6, 8
	the difference between 3 and 6 will always be smaller than 3 and 8
	so now, I limit my search to every two consecutive elements only.
		6 - 3 = 3
		8 - 6 = 2
	So shortest span is 2
	But 8 - 3 = 5 will never be smaller than 8 - 6 and 6 -3
*/
int Span::shortestSpan() const
{
	if (max <= 1 || numbers.size() <= 1)
		throw(spanTooSmall());
	std::vector<int> copy = numbers;
	std::sort(copy.begin(), copy.end());
	int min_span = std::numeric_limits<int>::max();
	for (std::vector<int>::const_iterator iter = copy.begin(); iter != copy.end() - 1; iter++) {
		int	diff = *(iter + 1) - *iter;
		if (diff < min_span)
			min_span = diff;
	}
	return (min_span);
}

int Span::longestSpan() const
{
	if (max <= 1 || numbers.size() <= 1)
		throw(spanTooSmall());

	std::vector<int>::const_iterator min_int;
	std::vector<int>::const_iterator max_int;

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

void	Span::printSpan() const
{
	for (std::vector<int>::const_iterator iter = numbers.begin(); iter != numbers.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}
