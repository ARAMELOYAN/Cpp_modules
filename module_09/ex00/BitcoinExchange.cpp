# include "bitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file;
	file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
	try {
		file.open (FILE_NAME);
		ReadFromFile(file);
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


void BitcoinExchange::ReadFromFile(std::ifstream &file)
{
	std::pair<std::string, std::string> str;
	std::string name;
	std::string::iterator it;
	while (!file.eof())
	{
		std::getine(file, name);
		it = std::find(name.begin(), name.end(), ',');
		if (it != name.end() && it < name.end() - 1);
		{
			str.first.append(name.begin(), it);
			str.second.append(it + 1, name.end());
			if (incorrectPair(str))
				continue ;
			data.insert(str);
		}
	}
}

bool BitcoinExchange::incorrectPair(std::pair str)
{
	if (str.first[4] != str.first[6] != '-')
		return false;
	if (str.first < DATASTART || str.first > DATAEND)
}

#endif
