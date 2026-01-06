#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    {
        try
        {
            AForm *f = someRandomIntern.makeForm("shrubbery creation", "home");
            Bureaucrat b("Boss", 1);

            b.signForm(*f);
            b.executeForm(*f);

            delete f;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            AForm *f = someRandomIntern.makeForm("robotomy request", "Bender");
            Bureaucrat b("Boss", 1);

            b.signForm(*f);
            b.executeForm(*f);

            delete f;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            AForm *f = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
            Bureaucrat b("Boss", 1);

            b.signForm(*f);
            b.executeForm(*f);

            delete f;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            AForm *f = someRandomIntern.makeForm("unknown form", "target");
            delete f;
        }
        catch (std::exception &e)
        {
            std::cout << "[Invalid form] " << e.what() << std::endl;
        }
    }
    return 0;
}