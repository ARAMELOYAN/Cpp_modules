#include "RPN.hpp"

RPN::RPN()
{
	std::cout << GREEN "RPN constructor" RESET "\n";
}

RPN::RPN(std::string str)
{
	std::string tokens("+-*/");
	std::string numbers("0123456789");
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	std::string::const_iterator token = str.begin();
	while (token < str.end())
	{
		if (numbers.find(*token) != std::string::npos)
			data.push(*token - 48);
		else if (tokens.find(*token) != std::string::npos && data.size() > 1)
		{
			if (*token == '+')
			{
				int val = data.top();
				data.pop();
				data.top() += val;
			}
			else if (*token == '-')
			{
				int val = data.top();
				data.pop();
				data.top() -= val;
			}
			else if (*token == '*')
			{
				int val = data.top();
				data.pop();
				data.top() *= val;
			}
			else
			{
				if (data.top() != 0)
				{
					int val = data.top();
					data.pop();
					data.top() /= val;
				}
				else
					throw std::runtime_error("Error: devide by zero");
			}
		}
		else
			throw std::runtime_error("Error: invalid token");
		++token;
	}
	if (data.size() != 1)
			throw std::runtime_error("Error: invalid expression");
	std::cout << GREEN "RPN parametric constructor" RESET "\n";
	std::cout << GREEN << data.top() << RESET "\n";
}

RPN::~RPN()
{
	std::cout << GREEN "RPN destructor" RESET "\n";
}

