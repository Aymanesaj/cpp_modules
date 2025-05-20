#include "phonebook.hpp"

void readLineOrExit(std::string &out)
{
	if (!std::getline(std::cin, out)){
		std::cout << "\nEOF detected. Exiting...\n";
		std::exit(0);
	}
}

void	add_contact(PhoneBook &phonebook)
{
	static int index = 0;
	std::string	input;

	std::cout << "What's your First Name :";
	readLineOrExit(input);
	phonebook.contacts[index].setFirstName(input);
	std::cout << "What's your Last Name :";
	readLineOrExit(input);
	phonebook.contacts[index].setLastName(input);
	std::cout << "What's your NickName :";
	readLineOrExit(input);
	phonebook.contacts[index].setNickname(input);
	std::cout << "What's your Phone Number :";
	readLineOrExit(input);
	while (!is_number(input))
	{
		std::cerr << "Invalid Phone Number" << std::endl;
		std::cout << "What's your Phone Number(For real this time??) :";
		readLineOrExit(input);
	}
	phonebook.contacts[index].setPhoneNumber(input);
	std::cout << "What's your Darkest Secret :";
	readLineOrExit(input);
	phonebook.contacts[index].setDarkestSecret(input);
	index = (index + 1) % 8;
	if (phonebook.size < 8)
		phonebook.size++;
}

int main()
{
	PhoneBook phonebook;
	std::string input;
	phonebook.size = 0;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		readLineOrExit(input);
		if (input == "EXIT")
		break ;
		else if (input == "ADD")
		add_contact(phonebook);
		else if (input == "SEARCH")
		search_phonebook(phonebook);
		else
		std::cerr << "Invalid Command" << std::endl;
	}
}