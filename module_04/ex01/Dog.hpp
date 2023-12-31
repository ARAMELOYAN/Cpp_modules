#ifndef DOG_HPP
# define DOG_HPP
# include "Brain.hpp"
# include "Animal.hpp"

class Dog: public Animal{
		Brain *brain;
	public:
		Dog();
		Dog( const Dog& dog);
		Dog& operator = ( const Dog& dog);
		~Dog();
		void makeSound() const;
};

#endif
