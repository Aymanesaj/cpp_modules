#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
public:
	void setFirstName(const std::string &fn);
	std::string	getFirstName();
	void setLastName(const std::string &ln);
    std::string getLastName();
	void setNickname(const std::string &nick);
    std::string getNickname();
	void setPhoneNumber(const std::string &ph);
    std::string getPhoneNumber();
	void setDarkestSecret(const std::string &ds);
    std::string getDarkestSecret();
	void display();
};

#endif