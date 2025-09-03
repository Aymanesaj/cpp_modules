#include "HumanB.hpp"

HumanB::HumanB(std::string Name):name(Name)
{}

void HumanB::setWeapon( Weapon &newWeapon )
{
    weapon = &newWeapon;
}

std::string HumanB::getName()
{
    return (name);
}

const std::string& HumanB::getWeaponType()
{
    return (weapon->getType());
}

void    HumanB::attack( void )
{
    std::cout << getName() << " attacks with their " << getWeaponType() << std::endl;
}