#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool  isSigned;
    const int grade_sign;
    const int grade_execute;
public:
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    Form(std::string name, int grade_sign, int grade_execute);
    void beSigned(Bureaucrat const &b);
    const std::string &getName() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    bool getIsSigned() const;
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class AlreadySigned : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif