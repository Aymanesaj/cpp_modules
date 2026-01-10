#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template<typename T>
class Array
{
private:
	unsigned int n;
	T *arr;
public:
	Array():n(0), arr(NULL){}
	Array(unsigned int n):n(n), arr(new T[n]()) {}
	Array(const Array& other):n(other.n), arr(NULL){ *this = other; }
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			T *old_arr = NULL;
			if (arr)
				old_arr = arr;
			n = other.n;
			arr = new T[n]();
			for (unsigned int i = 0; i < n; i++)
				arr[i] = other.arr[i];
			delete[] old_arr;
		}
		return (*this);
	}
	~Array() { delete[] arr; }
	T& operator[](unsigned int index)
	{
		if (index >= n)
			throw std::exception();
		return arr[index];
	}
	unsigned int size ( void ) const { return n; }
};

#endif