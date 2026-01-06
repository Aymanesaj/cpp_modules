#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie* zombies = zombieHorde(N, "heap");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
}
