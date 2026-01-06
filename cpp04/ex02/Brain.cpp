#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    operator=(other);
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other){
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

std::string Brain::getIdea(int idx) const
{
    if (idx < 0 || idx >= 100)
        return ("");
    return (ideas[idx]);
}

void    Brain::setIdea(int idx, std::string idea)
{
    if (idx < 0 || idx >= 100)
        return ;
    ideas[idx] = idea;
}