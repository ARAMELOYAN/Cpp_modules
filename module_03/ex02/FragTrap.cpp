#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "Chuni";
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << BLUE << "FragTrap Default Constructor Called!\n" << RESET;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << BLUE << "FragTrap Parametric Constructor Called!\n" << RESET;
}

FragTrap::FragTrap( const FragTrap& obj):ClapTrap(obj)
{
	std::cout << BLUE << "FragTrap Copy Constructor Called!\n" << RESET;
}

FragTrap& FragTrap::operator = ( const FragTrap& obj)
{
	if (&obj == this)
		return *this;
	std::cout << BLUE << "FragTrap Opeartor Assignment Called\n" << RESET;
	name = obj.name;
	hitPoint = obj.hitPoint;
	energyPoint = obj.energyPoint;
	attackDamage = obj.attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "FragTrap Destructor Called\n" << RESET;
}

void	FragTrap::attack(const std::string& target)
{
	if (energyPoint != 0)
	{
		--energyPoint;
		std::cout << BLUE << "FragTrap " << name << " attacks " << target << ", causing "
			<< attackDamage << " points of damage!\n" << RESET;
		return ;
	}
	std::cout << BLUE << "FragTrap " << name << " haven't energy points\n" << RESET;
}

void	FragTrap::highFivesGuys()
{
	std::cout << BLUE << "FragTrap need a high fives!\n" << RESET;
}
