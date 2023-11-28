#include <BitcoinExchange.hpp>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::ifstream file(av[1], std::ios::in);
		if (!file)
		{
			std::cerr << RED "FILE NOT FOUND" RESET "\n";
			return 0;
		}
		getline(char* s, streamsize n, char delim );
	}
}
