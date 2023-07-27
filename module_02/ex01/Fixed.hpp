#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed{
		int					fixedValue;
		static const int	fracBits = 8;
	public:
		Fixed();
		Fixed( const Fixed& obj );
		Fixed( const int val );
		Fixed( const float val );
		Fixed& operator = ( const Fixed& obj );
		~Fixed();
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
};
std::ostream& operator<< (std::ostream& out, const Fixed& obj);
#endif
