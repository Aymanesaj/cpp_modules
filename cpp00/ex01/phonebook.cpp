#include "phonebook.hpp"

int main()
{
	std::string input;
	while (true)
	{
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cin.clear();
			break ;
		}
		if (input == "EXIT")
			break ;
		else
			std::cerr << "Invalid Command" << std::endl;
	}
}