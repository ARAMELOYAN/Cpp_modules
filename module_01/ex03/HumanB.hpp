#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB{
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string name): _name(name){}
		void	setWeapon(Weapon& weapon){_weapon = &weapon;}
		void	attack(void);
};

#endif
