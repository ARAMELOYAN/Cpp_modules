#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
}

ScalarConverter::~ScalarConverter()
{
	std::cout << YELLOW << "ScalarConverter destructor" << RESET << "\n";
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter&)
{
	return *this;
}

ScalarConverter::ScalarConverter(std::string & obj)
{
	std::cout << CYAN << "ScalarConverter parametric constructor" << RESET << "\n";
	try
	{
		double val = parse(obj);
		toChar(val);
		toInt(val);
		toFloat(val);
		toDouble(val);
	}
	catch (std::exception &e)
	{
		std::string what = e.what();
		if (what == "nan")
		{
			std::cout << GREEN << "Char: impossible"RESET"\n";
			std::cout << GREEN << "Int: impossible"RESET"\n";
			std::cout << GREEN << "Float: nanf"RESET"\n";
			std::cout << GREEN << "Double: nan"RESET"\n";
		}
		else if (what[0] == '-')
		{
			std::cout << GREEN << "Char: impossible"RESET"\n";
			std::cout << GREEN << "Int: impossible"RESET"\n";
			std::cout << GREEN << "Float: -inff"RESET"\n";
			std::cout << GREEN << "Double: -inf"RESET"\n";
		}
		else if (what[0] == 'i')
		{
			std::cout << GREEN << "Char: impossible"RESET"\n";
			std::cout << GREEN << "Int: impossible"RESET"\n";
			std::cout << GREEN << "Float: inff"RESET"\n";
			std::cout << GREEN << "Double: inf"RESET"\n";
		}
		else
			std::cout << RED << what << RESET << "\n";
	}
}

double ScalarConverter::parse(std::string & obj)
{
	double val;

	if (obj == "nan")
		throw std::out_of_range(obj);
	if (obj == "-inf" || obj == "inf" || obj == "-inff" || obj == "inff")
		throw std::out_of_range(obj);
	if (!obj.length())
	{
		throw std::invalid_argument("Aegument count less than 1");
	}
	if (obj.length() == 1)
	{
		if (!isdigit(obj[0]))
			val = obj[0];
		else
			val = std::strtod(obj.c_str(), NULL);
	}
	else
	{
		if (obj[obj.length() - 1] == 'f')
			obj.std::string::erase(obj.end() - 1);
		val = std::strtod(obj.c_str(), NULL);
		if (errno == ERANGE)
			throw std::out_of_range("Out of range");
		if (val == 0.0 && (obj != "0" || obj != "0.0"))
			throw std::invalid_argument("Invalid argument");
	}
	return val;
}

void ScalarConverter::toChar(double val)
{
	try
	{
		if (val < 0 || val > 127)
		{
			throw std::out_of_range("Char: impossible");
		}
		if (!isprint(val))
			throw std::range_error(GREEN"Char: Non displayable");
		std::cout << GREEN << "Char: " << static_cast<char>(val) << RESET << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET"\n";
	}
}

void ScalarConverter::toInt(double val)
{
	try
	{
		if (val > INT_MAX || val < INT_MIN)
			throw std::out_of_range("Int: Out of range");
		std::cout << GREEN << "Int: " << static_cast<int>(val) << RESET << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET"\n";
	}
}

void ScalarConverter::toFloat(double val)
{
	std::cout << GREEN << "Float: " <<
		std::fixed << std::setprecision(1) << static_cast<float>(val) << "f"RESET"\n";
}

void ScalarConverter::toDouble(double val)
{
	std::cout << GREEN << "Double: " <<
		std::fixed << std::setprecision(1) << val << RESET"\n";
}
