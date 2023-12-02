# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << GREEN "BTC constructor" RESET "\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	if (this == &copy)
		return ;
	this->data = copy.data;
	std::cout << GREEN "BTC copy constructor" RESET "\n";
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& copy)
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


/*void BitcoinExchange::ImportData(std::ifstream& file, void (*my_func)(std::pair<std::string, std::string>))
{
	std::pair<std::string, std::string> my_pair;
	std::string name;
	std::string::iterator it;
	while (!file.eof())
	{
		std::getline(file, name);
		it = std::find(name.begin(), name.end(), ',');
		if (it != name.end() && it < name.end() - 1)
		{
			my_pair.first.assign(name.begin(), it);
			my_pair.second.assign(it + 1, name.end());
			if (!iscorrectPair(my_pair))
				continue ;
			my_func(my_pair);
		}
	}
}*/

void BitcoinExchange::ImportData(std::ifstream& file, BitcoinExchange::InsertFunctor insert)
{
	std::pair<std::string, std::string> my_pair;
	std::string line;
	std::string::iterator it;
	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << RED "ERROR: invalid file content " << line << " from " << BLUE DATA_FILE_NAME "\n" RESET;
		throw std::ifstream::failure("invalid format");
	}
	while (std::getline(file, line))
	{
		it = std::find(line.begin(), line.end(), ',');
		if (it < line.end() - 1)
		{
			my_pair.first.assign(line.begin(), it);
			my_pair.second.assign(it + 1, line.end());
			if (!IsValidDate(my_pair.first) || std::atof(my_pair.second.c_str()) < 0)
			{
				std::cerr << RED "ERROR: invalid data " << line << " from " << BLUE DATA_FILE_NAME "\n" RESET;
				continue ;
			}
			insert(my_pair);
		}
	}

}

void BitcoinExchange::ImportData(std::ifstream& file, BitcoinExchange::CalculateFunctor calculate)
{
	std::pair<std::string, std::string> my_pair;
	std::string name;
	std::string::iterator it;
	while (std::getline(file, name))
	{
		it = std::find(name.begin(), name.end(), '|');
		if (it != name.end() && it < name.end() - 1)
		{
			my_pair.first.assign(name.begin(), it);
			my_pair.second.assign(it + 1, name.end());
			if (!IsValidDate(my_pair.first) || !IsValidValue(my_pair.second))
				continue ;
			calculate(my_pair);
		}
	}
}

void BitcoinExchange::Insert(std::pair<std::string, std::string>& my_pair)
{
	data.insert(my_pair);
}

void BitcoinExchange::Calculate(std::pair<std::string, std::string>& my_pair)
{
	std::cout << YELLOW << my_pair.first << " => " << my_pair.second << std::endl;
}

bool BitcoinExchange::IsValidValue(const std::string& val_str) const
{
	if (std::atof(val_str.c_str()) > 1000 || std::atof(val_str.c_str()) < 0)
		return false;
	return true;
}

bool BitcoinExchange::IsValidDate(const std::string& date_str) const
{
	int maxDay;
	std::istringstream ss(date_str);
	std::tm tm = {};

	if (date_str[4] != '-' || date_str[7] != '-')
		return false;
	// Parse the date string into a std::tm structure manually
	ss >> tm.tm_year; // Year
	ss.ignore();       // Skip -
	ss >> tm.tm_mon;  // Month
	ss.ignore();       // Skip -
	ss >> tm.tm_mday; // Day

	// Adjust for the fact that tm_mon is zero-based
	tm.tm_mon--;

	// Check if the parsing was successful
	if (ss.fail()) {
		return false;
	}

	// Check if the values are within the valid range
	if (tm.tm_year < 1000 || tm.tm_year > 9999 || tm.tm_mon < 0 || tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > 31)
		return false;

	if (tm.tm_mon == 1) { // February
			      // Adjust for leap years
		maxDay = (tm.tm_year % 4 == 0 && (tm.tm_year % 100 != 0 || tm.tm_year % 400 == 0)) ? 29 : 28;
	} else {
		// For other months
		maxDay = (tm.tm_mon < 7) ? (tm.tm_mon % 2 == 0 ? 31 : 30) : (tm.tm_mon % 2 == 0 ? 30 : 31);
	}

	if (tm.tm_mday > maxDay)
	{
		std::cout << maxDay<< std::endl;
		return false;
	}
	if (date_str < DATE_START || date_str > DATE_END)
		return false;
	return true;
}
