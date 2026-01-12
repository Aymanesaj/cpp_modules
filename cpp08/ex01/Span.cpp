#include "Span.hpp"

Span::Span():N(0){}

Span::Span(unsigned int N):N(N){}

Span::Span(const Span& other):N(other.N), numbers(other.numbers) {}

Span& Span::operator=(const Span &other)
{
	if (this != &other){
		N = other.N;
		numbers = other.numbers;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int New)
{
	if (numbers.size() < N)
	{
		numbers.push_back(New);
		return ;
	}
	throw std::out_of_range("Exceeded the maximum capacity.");
}

int	Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::sort(numbers.begin(), numbers.end());
	return numbers[numbers.size() - 1] - numbers[0];
}

int	Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::sort(numbers.begin(), numbers.end());
	int span = numbers[1] - numbers[0];
	for (size_t i = 2; i < numbers.size(); i++)
	{
		if (span > numbers[i] - numbers[i - 1])
			span = numbers[i] - numbers[i - 1];
	}
	return (span);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int distance = std::distance(begin, end);
	if (numbers.size() + distance > N)
			throw std::out_of_range("Exceeded the maximum capacity.");
	numbers.insert(numbers.end(), begin, end);
}