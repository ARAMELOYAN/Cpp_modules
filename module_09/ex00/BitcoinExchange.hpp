#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"
# define FILE_NAME "data.cvs"
# define DATE_START "2009-01-02"
# define DATE_END "2022-03-29"
# include <iostream>
# include <algorithm>
# include <map>
# include <istream>
# include <string>
# include <sstream>
# include <iomanip>
# include <chrono>
# include <ctime>

class BitcoinExchange {
		std::map<std::string, std::string> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator = (const BitcoinExchange &copy);
		~BitcoinExchange();
		void ReadFromFile(std::ifstream& file);
		bool iscorrectPair(std::pair<std::string, std::string>& mypair) const;
		bool BitcoinExchange::isValidDate(const std::string& dateStr) const;
		};

#endif
