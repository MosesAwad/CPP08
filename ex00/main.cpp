
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	{
		int arr[] = {5, 7, 3 , 2, 8};
		std::vector<int> Vector(arr, arr + (sizeof(arr) / sizeof(arr[0])));
		try
		{
			std::vector<int>::iterator iter = easyfind(Vector, 5);
			std::cout << "Found -> " << *iter << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::list<int> List;

		List.push_back(5);
		List.push_back(7);
		List.push_back(3);
		List.push_back(2);
		List.push_back(8);

		try
		{
			std::list<int>::iterator iter = easyfind(List, 5);
			std::cout << "Found -> " << *iter << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
