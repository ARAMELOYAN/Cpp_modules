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

bool BitcoinExchange::iscorrectPair(std::pair& pair)
{
	if (pair.first[4] != pair.first[7] != '-')
		return false;
	if (!isValidDate(pair.first))
		return false;
	if (pair.first < DATASTART || pair.first > DATAEND)
		return false;
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) {
	std::istringstream ss = (dateStr);
	std::tm tm = {};
    
	// Parse the date string into a std::tm structure
	ss >> std::get_time(&tm, %Y-%m-%d);
    
	if (ss.fail()) {
		// Parsing failed
		return false;
	}

	// Convert std::tm to std::chrono::system_clock::time_point
	auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));

	// Check if the conversion resulted in a valid time point
	return tp.time_since_epoch().count() != -1;
}

#endif
