#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

Zombie::Zombie(){}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << GetName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::GetName( void )
{
	return (name);
}

void Zombie::SetName( std::string NewName )
{
	name = NewName;
}