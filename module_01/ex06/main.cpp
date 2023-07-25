#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl vlo;

	if (ac != 2)
		return 1;
	vlo.complain(av[1]);
	return 0;
}
