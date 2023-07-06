#include <iostream>

int main(int ac, char **av)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j < strlen(av[i]))
			std::cout << (char)toupper(av[i][j++]);
		std::cout << ' ';
		i++;
	}
	std::cout << std::endl;
	return 0;
}
