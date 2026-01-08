#include "Detect.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}