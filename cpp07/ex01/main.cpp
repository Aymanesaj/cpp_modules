#include "iter.hpp"

void print(const std::string& e)
{
    std::cout << e << std::endl;
}

void allUpper(std::string& e)
{
    for (size_t i = 0; i < e.length(); i++)
	{
		e[i] = std::toupper(e[i]);
	}
}

void allLower(std::string& e)
{
    for (size_t i = 0; i < e.length(); i++)
	{
		e[i] = std::tolower(e[i]);
	}
}

int main( void )
{
    std::string arr[] = {"aymANe", "fOo", "teMPlate"};
    const size_t len = 3;

	std::cout << "           \"TOUPPER\"            " << std::endl;
    iter(arr, len, allUpper);
	iter(arr, len, print);
	std::cout << "           \"tolower\"            " << std::endl;
	iter(arr, len, allLower);
	iter(arr, len, print);
    return 0;
}