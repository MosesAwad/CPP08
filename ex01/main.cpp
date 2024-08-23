
#include "Span.hpp"
#include <iostream>
#include <cstdlib> // For srand and rand
#include <ctime> // For time

int main()
{
	std::cout << "-------" << std::endl;
	std::cout << "Main 1 (Testing addNumber and maxSizeReached exception)" << std::endl;
	std::cout << "-------" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		try
		{
			sp.addNumber(83);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "-------" << std::endl;
	std::cout << "Main 2 (Testing the fill function)" << std::endl;
	std::cout << "-------" << std::endl;
	{
		Span sp = Span(10);
		std::vector<int> Vector;

		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < 10; i++) {
			Vector.push_back(rand() % 1000 + 1);
		}
		sp.fill(Vector.begin(), Vector.end());
		sp.printSpan();
		std::cout << std::endl;
	}

	std::cout << "-------" << std::endl;
	std::cout << "Main 3 (Testing a span of size 20000)" << std::endl;
	std::cout << "-------" << std::endl;		
	{
		Span sp = Span(20000);
		std::vector<int> Vector;

		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < 20000; i++) {
			Vector.push_back(rand() % 20000 + 1);
		}
		sp.fill(Vector.begin(), Vector.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << std::endl;
	}

	std::cout << "-------" << std::endl;
	std::cout << "Main 4 (Testing span functions on a Span of size 1)" << std::endl;
	std::cout << "-------" << std::endl;		
	{
		Span sp = Span(1);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try
		{
			sp.longestSpan();
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	/*
		Since we are asked by the subject PDF to cast N as an unsigned int, 
		I wouldn't be able to catch negative values since the number would 
		would wrap around from 4294967295 if it were negative. So there is 
		no way to catch it, even with an exception. So the only fix would be 
		to cast it as an int or long and then parse negative values manually 
		but since we are required to set it as an unsigned int, we just have 
		to accept the wraparound.
	*/
	std::cout << "-------" << std::endl;
	std::cout << "Main 5 (Attempting to initalize Span by sending a negative value to the constructor)" << std::endl;
	std::cout << "-------" << std::endl;		
	{
		try
		{
			Span sp = Span(-1);
			std::cout << "Success creating span" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "-------" << std::endl;
	std::cout << "Main 6 (Trying shortest and longest span on empty span with a non-zero max size)" << std::endl;
	std::cout << "-------" << std::endl;		
	{
		Span sp = Span(20);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try
		{
			sp.longestSpan();
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}
