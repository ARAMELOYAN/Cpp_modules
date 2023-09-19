#ifndef HEADER_HPP
# define HEADER_HPP
# include <iostream>
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class header
{
		const std::string _name;
	public:
		header();
		header(const header& obj);
		~header();
		header& operator = (const header& obj);
		header(std::string const& name);
};
#endif
