#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"
# include <iostream>

class WrongAnimal{
	protected:
		std::string		type;
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal& animal );
		WrongAnimal& operator = ( const WrongAnimal& animal );
		virtual ~WrongAnimal();
		void	makeSound() const;
		std::string getType() const;
};

#endif
