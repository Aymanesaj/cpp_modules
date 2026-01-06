#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name(""), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        grade = other.grade;
    }
    return (*this);
}

const std::string &Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::increment()
{
    if (grade > 1)
    {
        grade--;
        return ;
    }
    throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    if (grade < 150)
    {
        grade++;
        return ;
    }
    throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cerr << name << " signed " << f.getName() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << name << " couldn’t sign "
        << f.getName() << " because " << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}