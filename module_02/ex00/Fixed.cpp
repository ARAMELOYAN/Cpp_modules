#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedValue = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator = (const Fixed& fixed)
{
	if (this == &fixed)
		return *this;
	std::cout << "Copy assignment operator called\n";
	fixedValue = fixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return fixedValue;
}

void	Fixed::setRawBits(int value)
{
	this->fixedValue = value << this->fracBits;
	std::cout << "setRawBits member function called\n";
}
