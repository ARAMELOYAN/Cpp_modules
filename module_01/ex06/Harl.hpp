#ifndef HARL_H
# define HARL_H
# include <iostream>

class Harl{
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
	public:
		void			complain(std::string level);
		void			(*f[4])();
		int				 stringMass(std::string str);
};

#endif
