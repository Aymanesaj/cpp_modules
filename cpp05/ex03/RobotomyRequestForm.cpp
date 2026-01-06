#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other){
        AForm::operator=(other);
    }
    return (*this);
}

void RobotomyRequestForm::Action() const
{
    std::cout << "rat-a-tat-tat" << std::endl;
    std::srand(std::time(NULL));
    int rand = std::rand();
    if (rand % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << target << " robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}