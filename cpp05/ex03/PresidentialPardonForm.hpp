#ifndef PPF
#define PPF

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm();
    protected:
        void    Action() const;
};

#endif