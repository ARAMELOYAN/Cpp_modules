#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	name = "Chuni";
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << GREEN << "ScavTrap Default Constructor Called!\n" << RESET;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << GREEN << "ScavTrap Parametric Constructor Called!\n" << RESET;
}

ScavTrap::ScavTrap( const ScavTrap& obj):ClapTrap(obj)
{
	std::cout << GREEN << "ScavTrap Copy Constructor Called!\n" << RESET;
}

ScavTrap& ScavTrap::operator = ( const ScavTrap& obj)
{
	if (&obj == this)
		return *this;
	std::cout << GREEN << "ScavTrap Opeartor Assignment Called\n" << RESET;
	name = obj.name;
	hitPoint = obj.hitPoint;
	energyPoint = obj.energyPoint;
	attackDamage = obj.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN << "ScavTrap Destructor Called\n" << RESET;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energyPoint != 0)
	{
		--energyPoint;
		std::cout << GREEN << "ScavTrap " << name << " attacks " << target << ", causing "
			<< attackDamage << " points of damage!\n" << RESET;
		return ;
	}
	std::cout << GREEN << "ScavTrap " << name << " haven't energy points\n" << RESET;
}

void	ScavTrap::guardGate()
{
	std::cout << GREEN << "ScavTrap is now in Gate keeper mode.\n" << RESET;
}
