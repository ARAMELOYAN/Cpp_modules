#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain();
	type = "Cat";
	std::cout << PINK << "Cat Default Constructor Called\n" << RESET;
}

Cat::Cat (const Cat& cat)
{
	brain = new Brain(*cat.brain);
	type = cat.type;
	std::cout << PINK << "Cat Copy Constructor Called\n" << RESET;
}

Cat& Cat::operator = ( const Cat& cat )
{
	if (this == &cat)
		return *this;
	delete brain;
	brain = new Brain(*cat.brain);
	type = cat.type;
	std::cout << PINK << "Cat Operator Assignment Called\n" << RESET;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << PINK << "Cat Destructor Called\n" << RESET;
}

void Cat::makeSound() const
{
	std::cout << PINK << "myou! myooou!\n" << RESET;
}
