#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = std::string("Chuni");
	std::cout << RED <<  "ClapTrap Default Constructor called\n" << RESET;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

ClapTrap::ClapTrap(std::string name):name(name)
{
	std::cout << RED << "ClapTrap Parametric Constructor called\n" << RESET;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

ClapTrap::ClapTrap(const ClapTrap& obj):name(obj.name), hitPoint(obj.hitPoint),
	energyPoint(obj.energyPoint), attackDamage(obj.attackDamage)
{
	std::cout << RED << "ClapTrap copy Constructor called\n" << RESET;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& obj)
{

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
	if (energyPoint != 0)
	{
		--energyPoint;
		std::cout << RED << "ClapTrap " << name << " attacks " << target << ", causing "
			<< attackDamage << " points of damage!\n" << RESET;
		return ;
	}
	std::cout << RED << "ClapTrap " << name << " haven't energy points\n" << RESET;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (attackDamage < 30)
	{
		attackDamage += amount;
		if (attackDamage > 30)
			attackDamage = 30;
		std::cout << RED << "ClapTrap " << name << " taked " << amount <<" points of damage!\n" << RESET;
		return ;
	}
	std::cout << RED << "ClapTrap " << name << " aren't need a points of damage!\n" << RESET;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoint < 100)
	{
		--energyPoint;
		hitPoint += amount;
		if (hitPoint > 100)
			hitPoint = 100;
		std::cout << RED << "ClapTrap " << name << " taked " << amount <<" hit point!\n" << RESET;
		return ;
	}
	std::cout << RED << "ClapTrap " << name << " aren't need a hit point!\n" << RESET;
}
