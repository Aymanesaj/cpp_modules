#include "ClapTrap.hpp"

int main()
{
	ClapTrap one("One"), two("Two");

	one.attack("Two");
	two.takeDamage(0);
	two.beRepaired(0);
}