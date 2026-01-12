#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iterator>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	numbers;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span &other);
		~Span();
		void	addNumber(int New);
		int		shortestSpan();
		int		longestSpan();
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif