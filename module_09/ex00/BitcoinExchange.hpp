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
# include <fstream>
# define FILE_NAME "data.cvs"

class BitcoinExchange {
		std::map<std::string, float> data;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator = (const BitcoinExchange &copy);
		~BitcoinExchange();
};

#endif
