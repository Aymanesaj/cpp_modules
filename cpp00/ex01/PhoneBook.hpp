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
	PhoneBook();
	void	SearchPrompt();
	void	SearchPhonebook();
	void	AddContact();
};

#endif