#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { type = "WrongAnimal"; std::cout << "WrongAnimal constructor called" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal& other) { operator=(other) ; std::cout << "WrongAnimal copy constructor called" << std::endl; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal sound!" << std::endl;
}

std::string	WrongAnimal::getType() const { return (type); }