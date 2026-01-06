#include "PhoneBook.hpp"

void	UI::DisplayColumns(std::string	str)
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

bool	UI::IsNumber(const std::string& s)
{
    size_t it = 0;
    if (s.empty())
        return (false);
    if (s[it] == '+') ++it;
    while (s[it] && std::isdigit(s[it])) ++it;
    return (it == s.length());
}

void UI::ReadLineOrExit(std::string &out)
{
    while (true)
    {
        if (!std::getline(std::cin, out)){
            std::cout << "\nEOF detected. Exiting...\n";
            std::exit(0);
        }
        else if (out.empty())
            std::cout << "Empty Input ,try again : ";
        else
            break;
    }
}

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
