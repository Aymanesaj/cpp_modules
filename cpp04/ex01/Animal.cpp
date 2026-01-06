#include "Animal.hpp"

Animal::Animal() { type = "Animal"; std::cout << "Animal constructor called" << std::endl; }

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal& other) { operator=(other); std::cout << "Animal copy constructor called" << std::endl; }

Animal&	Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        type = other.getType();
    }
    return (*this);
}

void    Animal::makeSound( void ) const {}

std::string	Animal::getType() const { return (type); }