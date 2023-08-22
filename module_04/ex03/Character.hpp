#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

const unsigned char CHACHECOUNT = 255;
class Character: public ICharacter{
		std::string name;
		unsigned char INDEXCHACHE;
		AMateria *inventory[4];
		AMateria *archive[CHACHECOUNT + 1];
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
