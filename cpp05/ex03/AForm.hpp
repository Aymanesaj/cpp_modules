#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool  isSigned;
        const int grade_sign;
        const int grade_execute;
    public:
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        AForm(std::string name, int grade_sign, int grade_execute);
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
        class NotSigned : public std::exception
        {
            public:
                const char *what() const throw();
        };
        void execute(Bureaucrat const & executor) const ;
    protected:
        virtual void    Action() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif