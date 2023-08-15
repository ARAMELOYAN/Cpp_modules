#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

# include <iostream>

class Brain{
		std::string ideas[100];
	public:
		Brain();
		Brain( const Brain& br);
		Brain& operator = ( const Brain& br);
		~Brain();
		std::string getIdea(int index);
		void setIdea(std::string idea);
};

#endif
