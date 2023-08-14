#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << RED << "WrongAnimal Default Constructor Called\n" << RESET;
	type = "WhoAmI???";
}

WrongAnimal::WrongAnimal( const WrongAnimal& animal )
{
	std::cout << RED << "WrongAnimal Copy Constructor Called\n" << RESET;
	type = animal.type;
}

WrongAnimal& WrongAnimal::operator = ( const WrongAnimal& animal )
{
	if (this == &animal)
		return *this;
	type = animal.type;
	std::cout << RED << "WrongAnimal Operator Assignment Called\n" << RESET;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destructor Called\n" << RESET;
}

void WrongAnimal::makeSound() const
{
	std::cout << "myou? krrr? eee fsssss\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}
