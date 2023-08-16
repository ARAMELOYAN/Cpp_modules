#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
	std::cout<< Green << "Ice Default Constructor Called!\n" << RESET;
}

Ice::Ice (const Ice& ice):AMateria(ice)
{
	std::cout<< Green << "Ice Copy Constructor Called!\n" << RESET;
}

Ice& Ice::operator = ( const Ice& ice)
{
	if (this == &ice)
		return *this;
	this->type = ice->type;
	return *this;
}

Ice::~Ice()
{
	std::cout<< Green << "Ice Destructor Called!\n" << RESET;
}

Amateria* Ice::clone()
{
	Ice ice();

	return &ice;
}
