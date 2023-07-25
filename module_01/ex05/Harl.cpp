#include "Harl.hpp"

void	Harl::_debug( void )
{
	std::cout << "[DEBUG]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese"
		<< "-triple-pickle-specialketchup burger.\nI really do!\n";
}

void	Harl::_info( void )
{
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger!\n"
		<< "If you did, I wouldn’t be asking for more!\n";
}

void	Harl::_warning( void )
{
	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you"
		<< "started working here since last month.\n";
}

void	Harl::_error( void )
{
	std::cout << "[ERROR]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	void (Harl::*f[4])(void);
	int statemant;
	
	f[0] = &Harl::_debug;
	f[1] = &Harl::_info;
	f[2] = &Harl::_warning;
	f[3] = &Harl::_error;
	statemant = (level == "DEBUG") + 2 * (level == "INFO") +
		3 * (level == "WARNING") + 4 * (level == "ERROR");
	switch (statemant)
	{
		case 1:
			(this->*f[0])();
			break;
		case 2:
			(this->*f[1])();
			break;
		case 3:
			(this->*f[2])();
			break;
		case 4:
			(this->*f[3])();
			break;
		default:
			std::cout << "Please try again\n";
	}
}
