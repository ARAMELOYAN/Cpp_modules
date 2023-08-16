#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice{
	public:
		Ice();
		Ice( const Ice& ice );
		Ice& operator = ( const Ice& ice );
		virtual ~Ice();
		virtual AMateria* clone() const;
};
#endif