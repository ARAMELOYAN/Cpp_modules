#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << GREEN << "Dog Default Constructor Called\n" << RESET;
}

Dog::Dog( std::string toys ): Animal( toys )
{
	std::cout << GREEN << "Dog Parametric Constructor Called\n" << RESET;
}

Dog::Dog (const Dog& dog)
{
	type = dog.type;
	std::cout << GREEN << "Dog Copy Constructor Called\n" << RESET;
}

Dog& Dog::operator = ( const Dog& dog )
{
	if (this == &dog)
		return *this;
	type = dog.type;
	std::cout << GREEN << "Dog Operator Assignment Called\n" << RESET;
	return *this;
}

void Dog::makeSound()
{
	std::cout << GREEN << "HAF! HAF! HAF!\n" << RESET;
}
