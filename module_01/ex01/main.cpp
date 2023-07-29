#include "Zombie.hpp"

int main (void)
{
	Zombie *kuvaldu;

	kuvaldu = zombieHorde(10, "dynamic");
	for (int i = 0; i < 10; i++)
		kuvaldu[i].announce();
	delete [] kuvaldu;
	return 0;
}
