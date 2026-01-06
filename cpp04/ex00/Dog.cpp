#include "Dog.hpp"

Dog::Dog(): Animal() { type = "Dog"; std::cout << "Dog constructor called" << std::endl; }

Dog::Dog(const Dog& other) : Animal(other) { operator=(other); std::cout << "Dog copy constructor called" << std::endl; }

Dog& Dog::operator=(const Dog& other)
{
    Animal::operator=(other);
    return (*this);
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void    Dog::makeSound( void ) const 
{
    std::cout << "HawHaw Haw" << std::endl;
}