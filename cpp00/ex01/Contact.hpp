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
	/*setters and getters*/
	// first name
	void setFirstName(const std::string &fn) { FirstName = fn; }
	std::string	getFirstName() { return (FirstName); }
	// last name
	void setLastName(const std::string &ln)    { LastName = ln; }
    std::string getLastName()                  { return LastName; }
    // nickname
	void setNickname(const std::string &nick)  { Nickname = nick; }
    std::string getNickname()                  { return Nickname; }
    // phone number
	void setPhoneNumber(const std::string &ph) { PhoneNumber = ph; }
    std::string getPhoneNumber()               { return PhoneNumber; }
    // darkest secret
	void setDarkestSecret(const std::string &ds) { DarkestSecret = ds; }
    std::string getDarkestSecret()               { return DarkestSecret; }
	/* display contact info function */
	void display()
	{
		std::cout
			<< "First name: "    << getFirstName()    << std::endl
			<< "Last name: "     << getLastName()     << std::endl
			<< "Nickname: "      << getNickname()     << std::endl
			<< "Phone number: "  << getPhoneNumber()  << std::endl
			<< "Darkest secret: "<< getDarkestSecret()<< std::endl;
	}
};

#endif