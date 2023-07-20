#include "Zombie.hpp"

int main (void)
{
	Zombie kuvaldu = Zombie("normal");
	Zombie *kuvaldu_2;

	kuvaldu_2 = newZombie("pointer");
	kuvaldu.announce();
	kuvaldu_2->announce();
	randomChump("random");
	delete kuvaldu_2;
	return 0;
}
