#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bur("ANUN", 141);
	Form form("ddum", 140, 160);
	form.beSigned(bur);
	std::cout << form;
	return 0;
}
