#include "PhoneBook.hpp"
/*setters and getters*/

// first name

void Contact::setFirstName(const std::string &fn) { FirstName = fn; }
std::string	Contact::getFirstName() { return (FirstName); }
// last name

void Contact::setLastName(const std::string &ln)    { LastName = ln; }
std::string Contact::getLastName()                  { return LastName; }

// nickname
void Contact::setNickname(const std::string &nick)  { Nickname = nick; }
std::string Contact::getNickname()                  { return Nickname; }

// phone number
void Contact::setPhoneNumber(const std::string &ph) { PhoneNumber = ph; }
std::string Contact::getPhoneNumber()               { return PhoneNumber; }

// darkest secret
void Contact::setDarkestSecret(const std::string &ds) { DarkestSecret = ds; }
std::string Contact::getDarkestSecret()               { return DarkestSecret; }

/* display contact info function */
void Contact::display()
{
    std::cout
        << "First name: "    << getFirstName()    << std::endl
        << "Last name: "     << getLastName()     << std::endl
        << "Nickname: "      << getNickname()     << std::endl
        << "Phone number: "  << getPhoneNumber()  << std::endl
        << "Darkest secret: "<< getDarkestSecret()<< std::endl;
}
