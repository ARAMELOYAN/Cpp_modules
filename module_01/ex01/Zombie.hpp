#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie {
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name): _name(name){};
		~Zombie();
		void	setName(std::string name){_name = name;}
		void announce( void );
};

Zombie* zombieHorde( int N, std::string name );
Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
