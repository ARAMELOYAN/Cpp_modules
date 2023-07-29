#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed{
		int					fixedValue;
		static const int	fracBits = 8;
	public:
		Fixed();
		Fixed( const int val );
		Fixed( const float val );
		Fixed( const Fixed& obj );
		~Fixed();
		Fixed&	operator = ( const Fixed& obj );
		Fixed	operator + ( const Fixed& first);
		Fixed	operator - ( const Fixed& first);
		Fixed	operator * ( const Fixed& first);
		Fixed	operator / ( const Fixed& first);
		bool	operator > ( const Fixed& obj );
		bool	operator < ( const Fixed& obj );
		bool	operator >=( const Fixed& obj );
		bool	operator <=( const Fixed& obj );
		bool	operator ==( const Fixed& obj );
		bool	operator !=( const Fixed& obj );
		Fixed&	operator ++ ();
		Fixed	operator ++ (int);
		Fixed&	operator -- ();
		Fixed	operator -- (int);
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed& min(Fixed& one, Fixed& two)
		{
			if (one.fixedValue > two.fixedValue)
				return two;
			return one;
		}
		static const Fixed& min(const Fixed& one, const Fixed& two)
		{
			if (one.fixedValue > two.fixedValue)
				return two;
			return one;
		}
		static Fixed& max(Fixed& one, Fixed& two)
		{
			if (one.fixedValue < two.fixedValue)
				return two;
			return one;
		}
		static const Fixed& max(const Fixed& one, const Fixed& two)
		{
			if (one.fixedValue < two.fixedValue)
				return two;
			return one;
		}
};

std::ostream& operator<< (std::ostream& out, const Fixed& obj);

#endif
