#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called\n";
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name):name(name)
{
	std::cout << "ClapTrap Parametric Constructor called\n";
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj):name(obj.name), hitPoint(obj.hitPoint),
 energyPoint(obj.energyPoint), attackDamage(obj.attackDamage)
{
	std::cout << "ClapTrap copy Constructor called\n";
}

ClapTrap& ClapTrap::operator = (const ClapTrap& obj)
{
	name = obj.name;
	hitPoint = obj.hitPoint;
	energyPoint = obj.energyPoint;
	attackDamage = obj.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoint != 0)
	{
		--energyPoint;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
			<< attackDamage << " points of damage!\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " haven't energy points\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (attackDamage < 10)
	{
		attackDamage += amount;
		if (attackDamage > 10)
			attackDamage = 10;
		std::cout << "ClapTrap " << name << " taked " << amount <<" points of damage!\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " aren't need a points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoint < 10)
	{
		--energyPoint;
		hitPoint += amount;
		if (hitPoint > 10)
			hitPoint = 10;
		std::cout << "ClapTrap " << name << " taked " << amount <<" hit point!\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " aren't need a hit point!\n";
}
