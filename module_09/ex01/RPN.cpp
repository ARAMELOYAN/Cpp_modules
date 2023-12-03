#include "RPN.hpp"

RPN::RPN()
{
	std::cout << GREEN "RPN constructor" RESET "\n";
}

RPN::RPN(const std::string& str)
{
	std::cout << GREEN "RPN parametric constructor" RESET "\n";
}

RPN::RPN(const RPN& copy)
{
	std::cout << GREEN "RPN copy constructor" RESET "\n";
}

RPN& RPN::operator = (const RPN& copy)
{
	std::cout << GREEN "RPN assingnment operator" RESET "\n";
}

RPN::~RPN()
{
	std::cout << GREEN "RPN destructor" RESET "\n";
}

