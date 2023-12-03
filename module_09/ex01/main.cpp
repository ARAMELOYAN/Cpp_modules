#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn(av[1]);
	}
	else
		std::cout << RED "Error: invalid argument count\n" RESET;
	return 0;
}
