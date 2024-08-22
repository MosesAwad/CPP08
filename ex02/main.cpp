
#include "MutantStack.hpp"
#include <iostream>
#include <string>

template <typename T>
void		print_stack(MutantStack<T> stack) {
	typename MutantStack<T>::reverse_iterator start = stack.rbegin();
	typename MutantStack<T>::reverse_iterator end = stack.rend();
	for (typename MutantStack<T>::reverse_iterator iter = start; iter != end; iter++) {
		std::cout << *iter << std::endl;
	}
}

int main()
{
	{
		MutantStack<int> Good;

		Good.push(8);
		Good.push(3);

		print_stack(Good);
	}
	{
		MutantStack<std::string> Good;

		Good.push("Guys");
		Good.push("Hey");

		print_stack(Good);
	}
	return (0);
}
