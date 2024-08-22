
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>
#include <iostream>

/*
	In C++, the standard library stack and queue containers 
	are typically implemented using deque (double-ended queue) 
	as their underlying data structure.

	Deque supports this well because it provides efficient 
	access and modification at both the front and back.
  	
	* Efficiency: deques allows for efficient memory 
		usage compared to vector, especially when frequent insertions 
		and deletions are involved. This is because deque allocates 
		memory in chunks, reducing the need for frequent reallocations.
*/

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		// MutantStack(const MutantStack& other);
		// MutantStack& operator=(const MutantStack& other);
		~MutantStack() {};

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;

		iterator			begin(void) {return this->c.begin();};
		iterator			end(void) {return this->c.end();};
		reverse_iterator	rbegin(void) {return this->c.rbegin();};
		reverse_iterator	rend(void) {return this->c.rend();};
};

#endif