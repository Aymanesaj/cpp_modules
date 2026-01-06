#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():name(""), isSigned(false), grade_sign(150), grade_execute(150) {}

AForm::AForm(const AForm& other):name(other.name), isSigned(other.isSigned),
grade_sign(other.grade_sign), grade_execute(other.grade_execute) {}

AForm::AForm(std::string name, int grade_sign, int grade_execute)
:name(name), isSigned(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
    if (grade_sign < 1 || grade_execute < 1)
        throw GradeTooHighException();
    if (grade_execute > 150 || grade_sign > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.getName() << ", form grade to sign is " << obj.getGradeSign() 
    << " and grade to execute is " << obj.getGradeExecute() << ".";
    return (os);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *AForm::AlreadySigned::what() const throw()
{
    return "This form is already signed";
}

void AForm::beSigned(Bureaucrat &b)
{
    if (getIsSigned())
        throw AlreadySigned();
    else if (getGradeSign() >= b.getGrade())
        isSigned = true;
    else
        throw GradeTooLowException();
}

bool AForm::getIsSigned() const { return (isSigned); }

const std::string &AForm::getName() const { return (name); }

int AForm::getGradeSign() const { return (grade_sign); }

int AForm::getGradeExecute() const { return (grade_execute); }

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

AForm::~AForm() {}