#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria():type("GAS")
{
	std::cout<< RED << "AMateria default constructor called!\n" << RESET;
}

AMateria::AMateria( const AMateria& obj ):type(obj.type)
{
	std::cout<< RED << "AMateria copy constructor called!\n" << RESET;
}

AMateria::AMateria( std::string const& type ):type(type)
{
	std::cout<< RED << "AMateria parametric constructor called!\n" << RESET;
}

AMateria& AMateria::operator = ( const AMateria& obj )
{
	if (this == &obj)
		return *this;
	type = obj.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout<< RED << "AMateria destructor called!\n" << RESET;
}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use( ICharacter& target )
{
	std::cout  << RED << "What will i do target " << target.getName() << "?\n"
		<< RESET;
}
