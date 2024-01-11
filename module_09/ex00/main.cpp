#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::ifstream file;
		BitcoinExchange btc;
		try {
			file.exceptions ( std::ifstream::badbit );
			file.open (DATA_FILE_NAME);
			BitcoinExchange::InsertFunctor insertFunctor(&btc);
			btc.ImportData(file, insertFunctor);
			file.close();
			try {
				file.open (av[1]);
				BitcoinExchange::CalculateFunctor calculateFunctor(&btc);
				btc.ImportData(file, calculateFunctor);
				file.close();
			}
			catch (std::ifstream::failure& e) {
				std::cerr << "Exception opening/reading/closing " << av[1] << std::endl;
			}
		}
		catch (std::ifstream::failure& e) {
			std::cerr << "Exception opening/reading/closing " << DATA_FILE_NAME "\n";
			file.clear();
		}
	}
	else
		std::cout << RED "Error: invalid argument count\n" RESET;
	return 0;
}
