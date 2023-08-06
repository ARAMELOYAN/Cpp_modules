#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedValue = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called\n";
	fixedValue = val << fracBits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called\n";
	fixedValue = roundf( val * ( 1 << fracBits ));
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

////////////////////////////////////////////////////////////////////////////////

Fixed&	Fixed::operator = (const Fixed& fixed)
{
	if (this == &fixed)
		return *this;
	std::cout << "Copy assignment operator called\n";
	fixedValue =  fixed.fixedValue; 
	return *this;
}

Fixed	Fixed::operator + ( const Fixed& first)
{
	Fixed c;

	c.fixedValue = fixedValue + first.fixedValue; 
	return c;
}

Fixed	Fixed::operator - ( const Fixed& first)
{
	Fixed c;

	c.fixedValue = fixedValue - first.fixedValue; 
	return c;
}

Fixed	Fixed::operator * ( const Fixed& first)
{
	Fixed c;

	c.fixedValue = fixedValue * first.fixedValue / (1 << fracBits); 
	return c;
}

Fixed	Fixed::operator / ( const Fixed& first)
{
	Fixed c;

	c.fixedValue = (fixedValue * (1 << fracBits)) / first.fixedValue; 
	return c;
}

////////////////////////////////////////////////////////////////////////////////

bool	Fixed::operator > (const Fixed& obj)
{
	return fixedValue > obj.fixedValue;
}

bool	Fixed::operator < (const Fixed& obj)
{
	return fixedValue < obj.fixedValue;
}

bool	Fixed::operator >= (const Fixed& obj)
{
	return fixedValue >= obj.fixedValue;
}

bool	Fixed::operator <= (const Fixed& obj)
{
	return fixedValue <= obj.fixedValue;
}

bool	Fixed::operator == (const Fixed& obj)
{
	return fixedValue == obj.fixedValue;
}

bool	Fixed::operator != (const Fixed& obj)
{
	return fixedValue != obj.fixedValue;
}

////////////////////////////////////////////////////////////////////////////////

Fixed& Fixed::operator ++ ()
{
	++fixedValue;
	return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed copy(*this);

	++fixedValue;
	return copy;
}

Fixed& Fixed::operator -- ()
{
	--fixedValue;
	return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed copy(*this);

	--fixedValue;
	return copy;
}

////////////////////////////////////////////////////////////////////////////////

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return fixedValue;
}

void	Fixed::setRawBits(int value)
{
	std::cout << "setRawBits member function called\n";
	fixedValue = value;
}

int		Fixed::toInt(void) const
{
	return fixedValue >> fracBits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>( fixedValue ) / (1 << fracBits);
}

////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}
