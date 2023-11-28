# include "bitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file;
	file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
	try {
		file.open ("test.txt");
		while (!file.eof())
			file.get();
		file.close();
		std::cout << GREEN "BTC constructor" RESET "\n";
	}
	catch (std::ifstream::failure e) {
		std::cerr << "Exception opening/reading/closing file\n";
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	if (this == &copy)
		return ;
	this->data = copy.data;
	std::cout << GREEN "BTC copy constructor" RESET "\n";
}

BitcoinExchang& BitcoinExchange::operator = (const BitcoinExchange& copy)
{
	if (this == &copy)
		return *this;
	this->data = copy.data;
	std::cout << GREEN "BTC operator assignment" RESET "\n";
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << GREEN "BTC destructor" RESET "\n";
}


#endif
