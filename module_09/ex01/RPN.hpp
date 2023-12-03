#ifndef RPN_HPP
# define RPN_HPP
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"
# include <iostream>
# include <stack>
# include <algorithm>
# include <stdexcept>

class RPN
{
		std::stack<int> data;
		RPN(const RPN&);
		RPN& operator = (const RPN&);
	public:
		RPN();
		RPN(std::string str);
		~RPN();
};
#endif
