#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"
# include <iostream>

class ClapTrap{
		std::string		name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackDamage;
	public:
		ClapTrap();
		ClapTrap( std::string name);
		ClapTrap( const ClapTrap& obj );
		ClapTrap& operator = (const ClapTrap& obj);
		~ClapTrap();

		void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

};

#endif
