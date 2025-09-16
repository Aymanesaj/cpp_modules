#include "ScavTrap.hpp"

int main()
{
	ScavTrap one("One"), two("Two");

	one.attack("Two");
	two.takeDamage(20);
	two.beRepaired(20);
	one.guardGate();
}