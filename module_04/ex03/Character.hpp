#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter{
		std::string name;
		AMateria *inventory[4];
	public:
		Character();
		Character( const std::string name );
		Character( const Character& obj );
		Character& operator = ( const Character& obj );
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		~Character();
};
#endif
