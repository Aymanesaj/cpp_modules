#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { (void)other; return (*this); }

Intern::~Intern() {}

AForm* Intern::makeFormPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeFormRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::makeFormShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (Intern::*funcs[3])(const std::string&) = { &Intern::makeFormPresidential, &Intern::makeFormRobotomy, &Intern::makeFormShrubbery};
    for (size_t i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates" << formName << std::endl;
            return (this->*funcs[i])(target);
        }
    }
    std::cout << "Not a form name." << std::endl;
    return (NULL);
}
