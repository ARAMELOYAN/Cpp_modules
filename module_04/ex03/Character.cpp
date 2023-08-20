#include "Character.hpp"

unsigned char Character::INDEXCHACHE = 0;
AMateria *Character::unequiped[CHACHECOUNT + 1] = { nullptr };
Character::Character():name("WhoAmI")
{
	for ( int i = 0; i < 4; i++ )
		inventory[i] = nullptr;
	std::cout << YELLOW <<"Character Default constructor called \n" << RESET;
}

Character::Character(const std::string name): name(name)
{
	for ( int i = 0; i < 4; i++ )
		inventory[i] = nullptr;
	std::cout << YELLOW <<"Character parametric constructor called \n" << RESET;
}

Character::Character(const Character& obj): name(obj.name)
{
	std::cout << YELLOW <<"Character copy constructor called \n" << RESET;
	for (int i = 0; i < 4; i++)
	{
		if (obj.inventory[i])
		{
			delete inventory[i];
			inventory[i] = obj.inventory[i]->clone();
		}
		else
		{
			delete inventory[i];
			inventory[i] = nullptr;
		}
	}
}

Character& Character::operator = ( const Character& obj )
{
	if (this == &obj)
		return *this;
	name = obj.name;
	for (int i = 0; i < 4; i++)
	{
		if (obj.inventory[i])
		{
			delete inventory[i];
			inventory[i] = obj.inventory[i]->clone();
		}
		else
		{
			delete inventory[i];
			inventory[i] = nullptr;
		}
	}
	std::cout << YELLOW <<"Character operator assignment called \n" << RESET;
	return *this;
}

std::string const& Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (!inventory[i])
		{
			inventory[i] = m;
			break;
		}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (unequiped[INDEXCHACHE])
			delete unequiped[INDEXCHACHE];
		unequiped[INDEXCHACHE] = inventory[idx];
		inventory[idx] = nullptr;
		INDEXCHACHE++;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}

Character::~Character()
{
	int i = 0;

	while ( inventory[i] )
		delete inventory[i++];
	for (int i = 0; i <= CHACHECOUNT && unequiped[i]; i++)
		delete unequiped[i];
	std::cout << YELLOW <<"Character destructor called \n" << RESET;
}
