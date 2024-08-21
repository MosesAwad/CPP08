
#include <algorithm>
#include <exception>

class NotFound : public std::exception
{
	public:
		const char *what(void) const throw() {
			return ("Integer not found in iterator");
		}
};

/*
	SRCS:
	https://www.linkedin.com/pulse/dependent-names-rainer-grimm#:~:text=Trainer%20at%20Modernes%20C%2B%2B&text=A%20dependent%20name%20is%20essentially,the%20keywords%20typename%20or%20template.
*/
template <typename T>
typename T::iterator	easyfind(T& container, int find)
{
	// Doesn't work:
	// T<int>::iterator iter = std::find(container.begin(), container.end(), find);
	
	// Works:
	typename T::iterator iter = std::find(container.begin(), container.end(), find);

	if (iter == container.end())
		throw (NotFound());
	return iter;
}

/*
	Here, T::iterator is a dependent name and it is called dependent because it
	depends on the template parameter 'T' and what the actual template argument passed
	to it is gonna be, like std::vector<int> or std::list<int> for example. So, dependent 
	names typically occur within a template where the type or member names can depend on 
	the specific template arguments. 
	
	In general, dependent names need special handling in template code, especially 
	when they are used as types or members, to ensure that the compiler correctly 
	resolves them during the template instantiation process.

	The typename keyword here tells the compiler that T::iterator is a type, not a value 
	or a member function. Without this keyword, the compiler may assume T::iterator could 
	be a non-type member or might not parse it correctly. A non-type member means the compiler
	could think it's a something like:

		A static data member (e.g., T::iterator is an integer constant)
		A member function (e.g., T::iterator() is a constructor or function)
	
	By enforcing the typename keyword, C++ ensures consistency and clarity in template code 
	by letting the compiler know this member of the template T is a type, aka it has been 
	typedef'ed by the writers of C++, (because it could otherwise be interpreted as a static 
	member or a function instead if typename were omitted).

	For example, the class std::vector<int> could look like this:

	template <typename T>
	class vector {
	public:
		// Type aliases for iterator types
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef std::random_access_iterator_tag iterator_category;

		// Member functions for iterators
		iterator begin() { return data; }
		iterator end() { return data + size; }
		const_iterator begin() const { return data; }
		const_iterator end() const { return data + size; }

	private:
		T* data; // Pointer to the data
		std::size_t size; // Size of the vector
		std::size_t capacity; // Capacity of the vector
	};
*/