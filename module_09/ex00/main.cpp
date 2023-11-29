#include <BitcoinExchange.hpp>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::ifstream file;
		file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
		try {
			file.open (av[1]);
			file.close();
		}
		catch (std::ifstream::failure e) {
			std::cerr << Exception opening/reading/closing filen;
		}
	}
}
