#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        try
        {
            Bureaucrat a("Aymane", 42);
            Form f("Basic Form", 50, 30);
            std::cout << a << std::endl;
            std::cout << f << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Form f("Invalid Form", 0, 10);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat b("Bob", 10);
            Form f("Permit", 20, 5);

            b.signForm(f);
            std::cout << f << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat c("Charlie", 100);
            Form f("Secret Form", 50, 10);

            c.signForm(f);
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
            Form f("One-Time Form", 10, 5);

            d.signForm(f);
            d.signForm(f);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}