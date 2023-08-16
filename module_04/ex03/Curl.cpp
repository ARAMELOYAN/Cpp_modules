#include "Curl.hpp"

Curl::Curl():AMateria("curl")
{
	std::cout<< Green << "Curl Default Constructor Called!\n" << RESET;
}

Curl::Curl (const Curl& curl):AMateria(curl)
{
	std::cout<< Green << "Curl Copy Constructor Called!\n" << RESET;
}

Curl& Curl::operator = ( const Curl& curl)
{
	if (this == &curl)
		return *this;
	this->type = curl->type;
	return *this;
}

Curl::~Curl()
{
	std::cout<< Green << "Curl Destructor Called!\n" << RESET;
}

Amateria* Curl::clone()
{
	Curl curl();

	return &curl;
}
