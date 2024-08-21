
#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	private:
		std::vector<int>	numbers;
		unsigned int		max;
		Span();
	public:
		class maxSizeReached;
		Span(unsigned int N);
		Span& operator=(const Span& other);
		Span(const Span& other);
		~Span();

		void 	addNumber(int x);
		int		shortestSpan();
		int		longestSpan();
		void	fill(std::vector<int>::iterator start, std::vector<int>::iterator end);
};

class Span::maxSizeReached : public std::exception
{
	public:
		const char* what(void) const throw();
};

#endif