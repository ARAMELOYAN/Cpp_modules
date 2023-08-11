#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	name = "Chuni";
	ClapTrap::name = name + "_clap_name";
	hitPoint = FragTrap::hitPoint;
	energyPoint = ScavTrap::energyPoint;
	attackDamage = FragTrap::attackDamage;
	std::cout << YELLOW << "DiamondTrap Parametric Constructor Called!\n" << RESET;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->name = name;
	hitPoint = FragTrap::hitPoint;
	energyPoint = ScavTrap::energyPoint;
	attackDamage = FragTrap::attackDamage;
	std::cout << YELLOW << "DiamondTrap Parametric Constructor Called!\n" << RESET;
}

DiamondTrap::DiamondTrap( const DiamondTrap& obj): ClapTrap(obj)
{
	std::cout << YELLOW << "DiamondTrap Copy Constructor Called!\n" << RESET;
}

DiamondTrap& DiamondTrap::operator = ( const DiamondTrap& obj)
{
	if (&obj == this)
		return *this;
	std::cout << YELLOW << "DiamondTrap Opeartor Assignment Called\n" << RESET;
	name = obj.name;
	hitPoint = obj.hitPoint;
	energyPoint = obj.energyPoint;
	attackDamage = obj.attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "DiamondTrap Destructor Called\n" << RESET;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << YELLOW << "Hi, I am a " << name << "!\nMy Grandparent name is " <<
		ClapTrap::name << "\n" << RESET;
}
