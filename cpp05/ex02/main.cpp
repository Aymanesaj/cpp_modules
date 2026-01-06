#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        try
        {
            Bureaucrat a("Aymane", 1);
            ShrubberyCreationForm f("home");

            a.executeForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << "[Unsigned execute] " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat b("Bob", 150);
            RobotomyRequestForm f("Marvin");

            b.signForm(f);
            b.executeForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << "[Low grade execute] " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat c("Charlie", 1);
            ShrubberyCreationForm f("garden");

            c.signForm(f);
            c.executeForm(f);

            std::cout << "[Shrubbery] File created: garden_shrubbery" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat d("David", 1);
            RobotomyRequestForm f("Bender");

            d.signForm(f);
            d.executeForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat e("Eve", 1);
            PresidentialPardonForm f("Ford Prefect");

            e.signForm(f);
            e.executeForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat boss("Boss", 1);
            AForm *f = new PresidentialPardonForm("Arthur Dent");

            boss.signForm(*f);
            boss.executeForm(*f);

            delete f;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}