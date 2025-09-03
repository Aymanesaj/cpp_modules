#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string newType):type(newType)
{}

const std::string& Weapon::getType( void )
{
    return ( type );
}

void Weapon::setType( const std::string& newType )
{
    type = newType;
}
