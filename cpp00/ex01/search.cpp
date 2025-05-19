#include "phonebook.hpp"

void display(int idx, Contact *contacts)
{
	std::cout
		<< "First name: "    << contacts[idx].getFirstName()    << "\n"
		<< "Last name: "     << contacts[idx].getLastName()     << "\n"
		<< "Nickname: "      << contacts[idx].getNickname()     << "\n"
		<< "Phone number: "  << contacts[idx].getPhoneNumber()  << "\n"
		<< "Darkest secret: "<< contacts[idx].getDarkestSecret()<< "\n";
}

void	display_columns(std::string	str)
{
	int len;
	std::cout << str.substr(0, 9); 
	len = str.length();
	while (len++ < 10)
		std::cout << ' ';
	if (str.length() >= 10)
		std::cout << '.';
	std::cout << '|';
}

void	search_prompt(PhoneBook &phonebook)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "|   index  |first name|last name | nickname |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (size_t i = 0; i < phonebook.size; i++)
	{
		std::cout << "|    " << i << "     |";
		display_columns(phonebook.contacts[i].getFirstName());
		display_columns(phonebook.contacts[i].getLastName());
		display_columns(phonebook.contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool is_number(const std::string& s)
{
	int it = 0;
	if (s.empty())
		return (false);
	if (s[it] == '+') ++it;
	while (s[it] && std::isdigit(s[it])) ++it;
	return (it == s.length());
}

void	search_phonebook(PhoneBook &phonebook)
{
	search_prompt(phonebook);
	std::cout << "Enter index (0-7): ";
	int idx;
	std::string s;
	readLineOrExit(s);
	while (!is_number(s))
	{
		std::cerr << "Invalid input" << std::endl;
		std::cout << "Enter index (0-7): ";
		readLineOrExit(s);
	}
	std::stringstream ss(s);
	ss >> idx;
	if (idx < 0 || idx > 7 || idx >= phonebook.size)
	{
		std::cerr << "Invalid Index" << std::endl;
		return ;
	}
	display(idx, phonebook.contacts);
}
