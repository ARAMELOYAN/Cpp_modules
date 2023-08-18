#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
	std::cout<< GREEN << "Ice Default Constructor Called!\n" << RESET;
}

Ice::Ice (const Ice& ice):AMateria(ice)
{
	std::cout<< GREEN << "Ice Copy Constructor Called!\n" << RESET;
}

Ice& Ice::operator = ( const Ice& ice)
{
	if (this == &ice)
		return *this;
	this->type = ice.type;
	return *this;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *" << std::endl;
}

Ice::~Ice()
{
	std::cout<< GREEN << "Ice Destructor Called!\n" << RESET;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}
