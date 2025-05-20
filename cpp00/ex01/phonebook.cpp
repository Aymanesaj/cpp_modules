#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string input;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		UI::ReadLineOrExit(input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchPhonebook();
		else
			std::cerr << "Invalid Command" << std::endl;
	}
}
