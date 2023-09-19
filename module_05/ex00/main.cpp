#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bur("ANUN", 150);
		Bureaucrat hur("ASUN", 1);
		std::cout<< bur;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return 0;
}
