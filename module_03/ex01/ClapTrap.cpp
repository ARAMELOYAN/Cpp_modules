#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = std::string("Chuni");
	std::cout << RED <<  "ClapTrap Default Constructor called\n" << RESET;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ClapTrap::ClapTrap(std::string name):name(name)
{
	std::cout << RED << "ClapTrap Parametric Constructor called\n" << RESET;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ClapTrap::ClapTrap(const ClapTrap& obj):name(obj.name), hitPoint(obj.hitPoint),
	energyPoint(obj.energyPoint), attackDamage(obj.attackDamage)
{
	std::cout << RED << "ClapTrap copy Constructor called\n" << RESET;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& obj)
{

	if (&obj == this)
		return *this;
	std::cout << RED << "ClapTrap Operator Assignment called\n" << RESET;
	name = obj.name;
	hitPoint = obj.hitPoint;
	energyPoint = obj.energyPoint;
	attackDamage = obj.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Destructor called\n" << RESET;
}

void	ClapTrap::attack(const std::string& target)
{
	if ( hitPoint > 0 )
	{
		if (energyPoint != 0)
		{
			--energyPoint;
			std::cout << RED << "ClapTrap " << name << " attacks " << target << ", causing "
				<< attackDamage << " points of damage!\n" << RESET;
			return ;
		}
		std::cout << RED << "ClapTrap " << name << " haven't energy points\n" << RESET;
	}
	std::cout << RED << "ClapTrap " << name << " dead\n" << RESET;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoint > 0)
	{
		if (amount > hitPoint)
			hitPoint = 0;
		else
			hitPoint -= amount;
		std::cout << RED << "ClapTrap " << name << " lost " << amount << " hit point!\n"  << RESET;
		return ;
	}
	std::cout << RED << "ClapTrap " << name << " dead\n" << RESET;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ( energyPoint > 0 )
	{
		--energyPoint;
		hitPoint += amount;
		std::cout << RED << "ClapTrap " << name << " taked " << amount << " hit point!\n" << RESET;
		return ;
	}
	std::cout << RED << "ClapTrap " << name << " haven't energy points\n" << RESET;
}
