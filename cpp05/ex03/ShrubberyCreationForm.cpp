#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other){
        AForm::operator=(other);
    }
    return (*this);
}

void    ShrubberyCreationForm::Action() const
{
    std::ofstream output_file((target + "_shrubbery").c_str());
    if (!output_file.is_open()) return ;
    int height = 10;
    int i;
    for (i = 0; i < height; i++) {
        std::string spaces(height - i - 1, ' ');
        std::string stars(2 * i + 1, '*');
        
        output_file << spaces << stars << std::endl;
    }
    std::string trunkSpaces(height - 1, ' ');
    output_file << trunkSpaces << "|" << std::endl;
    output_file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}