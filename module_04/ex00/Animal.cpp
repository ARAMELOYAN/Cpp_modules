#include "Animal.hpp"

Animal::Animal()
{
	std::cout << RED << "Animal Default Constructor Called\n" << RESET;
	type = "WhoAmI???";
}

Animal::Animal( const Animal& animal )
{
	std::cout << RED << "Animal Copy Constructor Called\n" << RESET;
	type = animal.type;
}

Animal& Animal::operator = ( const Animal& animal )
{
	if (this == &animal)
		return *this;
	type = animal.type;
	std::cout << RED << "Animal Operator Assignment Called\n" << RESET;
	return *this;
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor Called\n" << RESET;
}

void Animal::makeSound() const
{
	std::cout << "myou? krrr? eee fsssss\n";
}
