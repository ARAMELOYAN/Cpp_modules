#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("Robert");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	DiamondTrap b("Serj");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	DiamondTrap c(a);
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	b = a;
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;

	b.whoAmI();
	b.guardGate();
	b.highFivesGuys();
	
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
