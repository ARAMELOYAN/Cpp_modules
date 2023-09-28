#include <iostream>
#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		ScalarConverter convert(str);
	}
	return 0;
}
