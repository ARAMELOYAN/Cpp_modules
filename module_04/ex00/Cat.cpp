#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << GREEN << "Cat Default Constructor Called\n" << RESET;
}

Cat::Cat (const Cat& cat)
{
	type = cat.type;
	std::cout << GREEN << "Cat Copy Constructor Called\n" << RESET;
}

Cat& Cat::operator = ( const Cat& cat )
{
	if (this == &cat)
		return *this;
	type = cat.type;
	std::cout << GREEN << "Cat Operator Assignment Called\n" << RESET;
	return *this;
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat Destructor Called\n" << RESET;
}

void Cat::makeSound() const
{
	std::cout << GREEN << "Krrrr eee Fsssss!\n" << RESET;
}
