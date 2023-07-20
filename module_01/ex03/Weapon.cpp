#include "Weapon.hpp"

Weapon::Weapon()
{
	_type = "";
	std::cout << "created Weapon without a type...\n";
}

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "Created Weapon the type of " << _type << "...\n";
}

void	Weapon::setType( std::string type)
{
	_type = type;
	std::cout << "The selected weapon type is " << _type << "...\n";
}
