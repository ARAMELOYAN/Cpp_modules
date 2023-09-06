#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bur("ANUN", 151);
	Form form("ddum", false, 130, 130);
	std::cout << form;
	return 0;
}
