#include "Bureaucrat.hpp"

int main()
{
    {
        try
        {
            Bureaucrat a("Aymane", 42);
            std::cout << a << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat b("Bob", 0);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat c("Charlie", 151);
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
            d.increment();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Bureaucrat e("Eve", 150);
            e.decrement();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}