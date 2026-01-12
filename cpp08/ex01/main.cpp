#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		try
		{
			Span sp(10000);

			std::srand(std::time(NULL));

			std::vector<int> v;
			v.reserve(10000);

			for (int i = 0; i < 10000; i++)
				v.push_back(std::rand());

			sp.addNumber(v.begin(), v.end());

			std::cout << "Inserted: 10000 numbers" << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;

			std::cout << "Trying to add one more number..." << std::endl;
			sp.addNumber(42);
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
}