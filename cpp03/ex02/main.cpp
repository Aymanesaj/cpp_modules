#include "FragTrap.hpp"

int main()
{
	FragTrap one("One"), two("Two");

	one.attack("Two");
	two.takeDamage(20);
	two.beRepaired(20);
	one.highFivesGuys();
}