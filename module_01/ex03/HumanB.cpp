#include "HumanB.hpp"

void HumanB::attack(void)
{
	std::cout << _name << " attacks with their "
		<< _weapon->getType() << std::endl;
}
