#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << PINK << "WrongCat Default Constructor Called\n" << RESET;
}

WrongCat::WrongCat (const WrongCat& cat): WrongAnimal(cat)
{
	type = cat.type;
	std::cout << PINK << "WrongCat Copy Constructor Called\n" << RESET;
}

WrongCat& WrongCat::operator = ( const WrongCat& cat )
{
	if (this == &cat)
		return *this;
	type = cat.type;
	std::cout << PINK << "WrongCat Operator Assignment Called\n" << RESET;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << PINK << "WrongCat Destructor Called\n" << RESET;
}

void WrongCat::makeSound() const
{
	std::cout << PINK << "myou! myooou!\n" << RESET;
}
