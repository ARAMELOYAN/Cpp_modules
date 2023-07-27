#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{
		int					fixedValue;
		static const int	fracBits = 8;
	public:
		Fixed();
		Fixed( const Fixed& obj );
		Fixed& operator = ( const Fixed& obj );
		~Fixed();
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
};
#endif
