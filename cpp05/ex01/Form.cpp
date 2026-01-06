#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():name(""), isSigned(false), grade_sign(150), grade_execute(150) {}

Form::Form(const Form& other):name(other.name), isSigned(other.isSigned),
grade_sign(other.grade_sign), grade_execute(other.grade_execute) {}

Form::Form(std::string name, int grade_sign, int grade_execute)
:name(name), isSigned(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if (grade_sign < 1 || grade_execute < 1)
        throw GradeTooHighException();
    if (grade_execute > 150 || grade_sign > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << obj.getName() << ", form grade to sign is " << obj.getGradeSign() 
    << " and grade to execute is " << obj.getGradeExecute() << ".";
    return (os);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *Form::AlreadySigned::what() const throw()
{
    return "This form is already signed";
}

void Form::beSigned(Bureaucrat const &b)
{
    if (getIsSigned())
        throw AlreadySigned();
    else if (getGradeSign() >= b.getGrade())
        isSigned = true;
    else
        throw GradeTooLowException();
}

bool Form::getIsSigned() const { return (isSigned); }

const std::string &Form::getName() const { return (name); }

int Form::getGradeSign() const { return (grade_sign); }

int Form::getGradeExecute() const { return (grade_execute); }

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

Form::~Form() {}