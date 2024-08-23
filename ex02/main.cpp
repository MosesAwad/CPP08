
#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

template <typename T>
void		print_stack(const MutantStack<T>& stack) {
	typename MutantStack<T>::const_reverse_iterator start = stack.rbegin();
	typename MutantStack<T>::const_reverse_iterator end = stack.rend();
	for (typename MutantStack<T>::const_reverse_iterator iter = start; iter != end; iter++) {
		std::cout << *iter << std::endl;
	}
}

int main()
{
	std::cout << "--------------- MAIN 1 -----------------" << std::endl;
	std::cout << "Testing basic stack operations" << std::endl;
	{
		MutantStack<int> Good;

		Good.push(8);
		Good.push(3);

		print_stack(Good);
	}
	std::cout << "--------------- MAIN 2 -----------------" << std::endl;
	std::cout << "Testing assignment operator of the MutantStack class" << std::endl;
	{
		MutantStack<std::string> Good;

		Good.push("Guys");
		Good.push("Hey");
		print_stack(Good);

		MutantStack<std::string> Bad = Good;
		print_stack(Bad);
	}
	std::cout << "--------------- MAIN 3 -----------------" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();	// must start at 5 cuz this is not a reverse iterator
		MutantStack<int>::iterator ite = mstack.end();	// must end at NULL beyond 0 cuz this is not a reverse iterator

		++it;	// pushes iterator to the next element in the stack which is 3 now since 17 was popped
		--it;	// bringd back the iterator to the previous element in the stack which is 5

		std::cout << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "--------------- MAIN 4 -----------------" << std::endl;
	{
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;

		std::cout << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}
