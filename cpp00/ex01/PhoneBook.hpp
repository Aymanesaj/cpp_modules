#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int		size;
	int		index;
public:
	PhoneBook(){size = 0;index = 0;}
	void	SearchPrompt()
	{
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "|   index  |first name|last name | nickname |" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << "|    " << i << "     |";
			UI::DisplayColumns(contacts[i].getFirstName());
			UI::DisplayColumns(contacts[i].getLastName());
			UI::DisplayColumns(contacts[i].getNickname());
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	void	SearchPhonebook()
	{
		SearchPrompt();
		std::cout << "Enter index (0-7): ";
		int idx;
		std::string s;
		UI::ReadLineOrExit(s);
		while (!UI::IsNumber(s))
		{
			std::cerr << "Invalid input" << std::endl;
			std::cout << "Enter index (0-7): ";
			UI::ReadLineOrExit(s);
		}
		std::stringstream ss(s);
		ss >> idx;
		if (idx < 0 || idx > 7 || idx >= size)
		{
			std::cerr << "Invalid Index" << std::endl;
			return ;
		}
		contacts[idx].display();
	}
	void	AddContact()
	{
		std::string	input;

		std::cout << "What's your First Name :";
		UI::ReadLineOrExit(input);
		contacts[index].setFirstName(input);
		std::cout << "What's your Last Name :";
		UI::ReadLineOrExit(input);
		contacts[index].setLastName(input);
		std::cout << "What's your NickName :";
		UI::ReadLineOrExit(input);
		contacts[index].setNickname(input);
		std::cout << "What's your Phone Number :";
		UI::ReadLineOrExit(input);
		while (!UI::IsNumber(input))
		{
			std::cerr << "Invalid Phone Number" << std::endl;
			std::cout << "What's your Phone Number :";
			UI::ReadLineOrExit(input);
		}
		contacts[index].setPhoneNumber(input);
		std::cout << "What's your Darkest Secret :";
		UI::ReadLineOrExit(input);
		contacts[index].setDarkestSecret(input);
		index = (index + 1) % 8;
		if (size < 8)
			size++;
	}
};

#endif