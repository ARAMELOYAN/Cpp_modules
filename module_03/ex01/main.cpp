#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Robert");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	ScavTrap b("Serj");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	ScavTrap c(a);
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	b = a;
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;

	b.guardGate();
	
	b.attack("Nikol");

	b.attack("Nikol");

	for (int i = 0; i < 3; i++)
		b.attack("Nikol");

	for (int i = 0; i < 2; i++)
		b.attack("Nikol");

	b.takeDamage(101);
	b.attack("Nikol");
	
	b.beRepaired(5);

	b.beRepaired(5);
	b.takeDamage(3);
	
	return (0);
}
