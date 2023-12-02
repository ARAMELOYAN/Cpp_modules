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
# define DATA_FILE_NAME "data.csv"
# define DATE_START "2009-01-02"
# define DATE_END "2022-03-29"
# include <iostream>
# include <algorithm>
# include <map>
# include <fstream>
# include <string>
# include <sstream>
# include <iomanip>
# include <ctime>

class BitcoinExchange {
	std::map<std::string, std::string> data;
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator = (const BitcoinExchange &copy);
	~BitcoinExchange();
	struct InsertFunctor {
		BitcoinExchange* btc;

		InsertFunctor(BitcoinExchange* b) : btc(b) {}

		void operator()(std::pair<std::string, std::string>& pair) {
			btc->Insert(pair);
		}
	};

	// Function object for Calculate
	struct CalculateFunctor {
		BitcoinExchange* btc;

		CalculateFunctor(BitcoinExchange* b) : btc(b) {}

		void operator()(std::pair<std::string, std::string>& pair) {
			btc->Calculate(pair);
		}
	};

	void ImportData(std::ifstream& file, InsertFunctor insert);
	void ImportData(std::ifstream& file, CalculateFunctor calculate);
	//void ImportData(std::ifstream& file, void (*my_func)(std::pair<std::string, std::string>));
	void Insert(std::pair<std::string, std::string>& my_pair);
	void Calculate(std::pair<std::string, std::string>& my_pair);
	bool IsValidDate(const std::string& dateStr) const;
	bool IsValidValue(const std::string& dateStr) const;
};
#endif
