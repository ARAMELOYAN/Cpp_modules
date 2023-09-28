#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bur("ANUN", 141);
		Form form("ddum", 140, 150);
		form.beSigned(bur);
		bur.increment();
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET;
	}
	return 0;
}
