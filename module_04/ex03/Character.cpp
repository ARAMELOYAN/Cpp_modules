#include "Character.hpp"

Character::Character():name("WhoAmI"),
	INDEXCHACHE(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
	for (int i = 0; i <= CHACHECOUNT; i++)
		archive[i] = nullptr;
	std::cout << YELLOW <<"Character Default constructor called \n" << RESET;
}

Character::Character(const std::string name): name(name),
	INDEXCHACHE(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
	for (int i = 0; i <= CHACHECOUNT; i++)
		archive[i] = nullptr;
	std::cout << YELLOW <<"Character parametric constructor called \n" << RESET;
}

Character::Character(const Character& obj): name(obj.name),
	INDEXCHACHE(obj.INDEXCHACHE)
{
	int i = 0;

	std::cout << YELLOW <<"Character copy constructor called \n" << RESET;
	for (int i = 0; i < 4; i++)
	{
		if (obj.inventory[i])
			inventory[i] = obj.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
	while (i <= CHACHECOUNT)
	{
		if (obj.archive[i])
			archive[i] = obj.archive[i]->clone();
		else
			archive[i] = nullptr;
		i++;
	}
}

Character& Character::operator = ( const Character& obj )
{
	int i = 0;

	INDEXCHACHE = obj.INDEXCHACHE;
	if (this == &obj)
		return *this;
	name = obj.name;
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
		if (obj.inventory[i])
			inventory[i] = obj.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
	while ( i <= CHACHECOUNT )
	{
		delete archive[i];
		if (obj.archive[i])
			archive[i] = obj.archive[i]->clone();
		else
			archive[i] = nullptr;
		i++;
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
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		if (archive[INDEXCHACHE])
			delete archive[INDEXCHACHE];
		archive[INDEXCHACHE] = inventory[idx];
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
	for (int i = 0; i <= CHACHECOUNT && archive[i]; i++)
	{
		AMateria* temp;

		temp = archive[i];
		for (int j = i + 1; j <= CHACHECOUNT; j++)
			if (archive[j] == temp)
				archive[j] = nullptr;
		delete archive[i];
		archive[i] = nullptr;
	}
	std::cout << YELLOW <<"Character destructor called \n" << RESET;
}
