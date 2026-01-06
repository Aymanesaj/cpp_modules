#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name") , FragTrap("_clap_name"), ScavTrap("_clap_name"), _name()
{
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string newname): ClapTrap(newname + "_clap_name") ,FragTrap(newname + "_clap_name")
				, ScavTrap(newname + "_clap_name"), _name(newname)
{
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	operator=(other);
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other){
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap name: " << Name << std::endl << "DiamondTrap name: " << _name << std::endl;
}