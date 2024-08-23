
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
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
		MutantStack(const MutantStack& other) : std::stack<T>(other) {*this = other;};
		MutantStack& operator=(const MutantStack& other) {if (this != &other) {std::stack<T>::operator=(other);} return (*this);};
		~MutantStack() {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator			begin() {return this->c.begin();};
		iterator			end() {return this->c.end();};

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin() {return this->c.rbegin();};
		reverse_iterator	rend() {return this->c.rend();};

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator		begin() const {return this->c.begin();};
		const_iterator		end() const {return this->c.end();};

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator		rbegin() const {return this->c.rbegin();};
		const_reverse_iterator		rend() const {return this->c.rend();};
};

#endif