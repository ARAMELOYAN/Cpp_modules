#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie {
		std::string	_name;
	public:
		Zombie(std::string name): _name(name){};
		~Zombie();
		void announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
