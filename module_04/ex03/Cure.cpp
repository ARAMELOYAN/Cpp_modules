#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
	std::cout<< GREEN << "Cure Default Constructor Called!\n" << RESET;
}

Cure::Cure (const Cure& cure):AMateria(cure)
{
	std::cout<< GREEN << "Cure Copy Constructor Called!\n" << RESET;
}

Cure& Cure::operator = ( const Cure& cure)
{
	if (this == &cure)
		return *this;
	this->type = cure.type;
	return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure()
{
	std::cout<< GREEN << "Cure Destructor Called!\n" << RESET;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}
