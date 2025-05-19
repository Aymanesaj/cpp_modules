#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	// first name
	void setFirstName(const std::string &fn) { first_name = fn; }
	std::string	getFirstName() { return (first_name); }
	// last name
	void setLastName(const std::string &ln)    { last_name     = ln; }
    std::string getLastName()                  { return last_name; }
    // nickname
	void setNickname(const std::string &nick)  { nickname      = nick; }
    std::string getNickname()                  { return nickname; }
    // phone number
	void setPhoneNumber(const std::string &ph) { phone_number  = ph; }
    std::string getPhoneNumber()               { return phone_number; }
    // darkest secret
	void setDarkestSecret(const std::string &ds) { darkest_secret = ds; }
    std::string getDarkestSecret()               { return darkest_secret; }
};

class PhoneBook
{
private:
public:
	Contact contacts[8];
	int		size;
	
};

void	search_phonebook(PhoneBook &phonebook);
bool 	is_number(const std::string& s);
void 	readLineOrExit(std::string &out);

#endif