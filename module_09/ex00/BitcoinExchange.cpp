# include "BitcoinExchange.hpp"

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


void BitcoinExchange::ReadFromFile(std::ifstream &file)
{
	std::pair<std::string, std::string> str;
	std::string name;
	std::string::iterator it;
	while (!file.eof())
	{
		std::getline(file, name);
		it = std::find(name.begin(), name.end(), ',');
		if (it != name.end() && it < name.end() - 1)
		{
			str.first.append(name.begin(), it);
			str.second.append(it + 1, name.end());
			if (iscorrectPair(str))
				continue ;
			data.insert(str);
		}
	}
}

bool BitcoinExchange::iscorrectPair(std::pair<std::string, std::string>& mypair) const
{
	if (mypair.first[4] != '-' || mypair.first[7] != '-')
		return false;
	if (!isValidDate(mypair.first))
		return false;
	if (mypair.first < DATE_START || mypair.first > DATE_END)
		return false;
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) const
{
	
    std::istringstream ss(dateStr);
    std::tm tm = {};

    // Parse the date string into a std::tm structure
    ss >> std::get_time(&tm, "%Y-%m-%d");

    // Check if the parsing was successful
    if (ss.fail()) {
        return false;
    }

    // Check if the values are within the valid range
    if (tm.tm_year + 1900 < 1000 || tm.tm_year + 1900 > 9999 || tm.tm_mon < 0
			|| tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > 31)
        return false;

	int maxDay;
	if (tm.tm_mon == 1) { // February
		// Adjust for leap years
		maxDay = (tm.tm_year % 4 == 0 && (tm.tm_year % 100 != 0 || tm.tm_year % 400 == 0)) ? 29 : 28;
	} else {
		// For other months
		maxDay = (tm.tm_mon < 7) ? (tm.tm_mon % 2 == 0 ? 30 : 31) : (tm.tm_mon % 2 == 0 ? 31 : 30);
	}

	if (tm.tm_mday > maxDay) {
		std::cout << "Invalid day for the given month.\n";
		return false;
	}
	return true;
}
