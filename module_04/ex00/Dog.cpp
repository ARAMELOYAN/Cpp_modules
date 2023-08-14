#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << GREEN << "Dog Default Constructor Called\n" << RESET;
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

Dog::~Dog()
{
	std::cout << GREEN << "Dog Destructor Called\n" << RESET;
}

void Dog::makeSound() const
{
	std::cout << GREEN << "HAF! HAF! HAF!\n" << RESET;
}
