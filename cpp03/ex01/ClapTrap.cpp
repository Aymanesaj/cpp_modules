#include "ClapTrap.hpp"

ClapTrap::ClapTrap():Name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0) { std::cout << "Default constructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& other) { operator=(other); std::cout << "Copy constructor called" << std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other){
        Name = other.Name;
        AttackDamage = other.AttackDamage;
        EnergyPoints = other.EnergyPoints;
        HitPoints = other.HitPoints;
    }
    return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl; }

ClapTrap::ClapTrap(std::string name):Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) { std::cout << "Parameterized constructor called" << std::endl; }

void ClapTrap::attack(const std::string& target)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << "ClapTrap " << Name <<  " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << Name << " takes " << amount << " points of damage!" << std::endl;
    HitPoints -= amount;
    if (HitPoints < 0)
        HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << Name << " is repaired for " << amount << " hit points!" << std::endl;
        HitPoints += amount;
        EnergyPoints--;
    }
}