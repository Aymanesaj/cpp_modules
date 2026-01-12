#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <deque>

template<typename T>
void easyfind(T arr, int a)
{
	typename T::iterator it = std::find(arr.begin(), arr.end(), a);
	if (it == arr.end()){
		throw std::out_of_range("Element not found");
	}
	std::cout << "Element found at position: "
	<< std::distance(arr.begin(), it) << std::endl;
}

#endif