#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    brain = new Brain();
    type = "Cat";
}

Cat::Cat(const Cat& other): Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    return (*this);
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; delete brain; }

void    Cat::makeSound( void ) const 
{
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return (brain);
}