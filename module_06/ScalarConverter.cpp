#include "header.hpp"

header::header()
{
	std::cout << CYAN << "header default constructor" << RESET << "\n";
}

header::header(const header& obj)
{
	std::cout << CYAN << "header copy constructor" << RESET << "\n";
}

header::~header()
{
	std::cout << YELLOW << "header destructor" << RESET << "\n";
}

header& header::operator = (const header& obj)
{
	std::cout << CYAN << "header copy assignment operator" << RESET << "\n";
}
