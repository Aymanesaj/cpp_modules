#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    AForm* makeForm(std::string formName, std::string target);
    AForm* makeFormPresidential(const std::string &target);
    AForm* makeFormRobotomy(const std::string &target);
    AForm* makeFormShrubbery(const std::string &target);
    AForm* (*funcs[3])() ;
};
