#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon& Weapon):weapon(Weapon), name(Name)
{}

std::string HumanA::getName()
{
    return (name);
}

const std::string& HumanA::getWeaponType()
{
    return (weapon.getType());
}

void    HumanA::attack( void )
{
    std::cout << getName() << " attacks with their " << getWeaponType() << std::endl;
}
