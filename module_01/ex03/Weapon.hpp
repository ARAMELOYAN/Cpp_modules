#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon{
		std::string	_type;
	public:
		Weapon();
		Weapon(std::string type);
		const std::string&	getType(){return _type;}
		void				setType(std::string type);
};

#endif
