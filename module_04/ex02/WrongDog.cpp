#include "WrongDog.hpp"

WrongDog::WrongDog()
{
	type = "WrongDog";
	std::cout << GREEN << "WrongDog Default Constructor Called\n" << RESET;
}

WrongDog::WrongDog (const WrongDog& dog): WrongAnimal(dog)
{
	type = dog.type;
	std::cout << GREEN << "WrongDog Copy Constructor Called\n" << RESET;
}

WrongDog& WrongDog::operator = ( const WrongDog& dog )
{
	if (this == &dog)
		return *this;
	type = dog.type;
	std::cout << GREEN << "WrongDog Operator Assignment Called\n" << RESET;
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << GREEN << "WrongDog Destructor Called\n" << RESET;
}

void WrongDog::makeSound() const
{
	std::cout << GREEN << "HAF! HAF! HAF!\n" << RESET;
}
