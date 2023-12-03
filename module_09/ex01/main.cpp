#include "RPN.hpp"

int main(int ac, char **av)
{
	try {
	if (ac == 2)
	{
		RPN rpn(av[1]);
	}
	else
		std::cout << RED "Error: invalid argument count\n" RESET;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}
