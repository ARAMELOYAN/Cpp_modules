#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cerrno>
# include <cctype>
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class ScalarConverter
{
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator = (const ScalarConverter& obj);
	public:
		~ScalarConverter();
		ScalarConverter(std::string &obj);
		double	parse(std::string &obj);
		void	toChar(double i);
		void	toInt(double i);
		void	toFloat(double i);
		void	toDouble(double i);
};
#endif
