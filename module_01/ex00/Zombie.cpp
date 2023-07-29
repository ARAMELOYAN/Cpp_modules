#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << _name << ": Died\n";
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
