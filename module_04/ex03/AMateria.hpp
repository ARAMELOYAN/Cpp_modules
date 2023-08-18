#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class AMateria{
	protected:
		std::string type;
	public:
		AMateria ();
		AMateria ( const AMateria& obj );
		AMateria ( std::string const& type );
		AMateria& operator = ( const AMateria& obj );
		virtual ~AMateria ();
		std::string const& getType () const;
		virtual AMateria* clone() const = 0;
		virtual void use( ICharacter& target );
};
#endif
