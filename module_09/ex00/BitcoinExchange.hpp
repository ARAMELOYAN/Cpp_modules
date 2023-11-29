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
# include <iostream>
# include <ifstream>
# define FILE_NAME "data.cvs"
# define DATASTART "2009-01-02"
# define DATAEND "2022-03-29"

class BitcoinExchange {
		std::map<std::string, std::string> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator = (const BitcoinExchange &copy);
		~BitcoinExchange();
		void ReadFromFile(std::ifstream& file);
		bool incorrectPair(std::pair<std::string, std::string>& pair) const;
		bool BitcoinExchange::isValidDate(const std::string& dateStr) const 
		};

#endif
