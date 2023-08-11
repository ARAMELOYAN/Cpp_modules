#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap{
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& obj );
		DiamondTrap& operator = ( const DiamondTrap& obj );
		~DiamondTrap();

		virtual void attack( const std::string& target );
		void whoAmI();
};

#endif
