#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << RED << "AAnimal Default Constructor Called\n" << RESET;
	type = "WhoAmI???";
}

AAnimal::AAnimal( const AAnimal& animal )
{
	std::cout << RED << "AAnimal Copy Constructor Called\n" << RESET;
	type = animal.type;
}

AAnimal& AAnimal::operator = ( const AAnimal& animal )
{
	if (this == &animal)
		return *this;
	type = animal.type;
	std::cout << RED << "AAnimal Operator Assignment Called\n" << RESET;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal Destructor Called\n" << RESET;
}

std::string AAnimal::getType() const
{
	return type;
}
