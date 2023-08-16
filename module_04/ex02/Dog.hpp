#ifndef DOG_HPP
# define DOG_HPP
# include "Brain.hpp"
# include "AAnimal.hpp"

class Dog: public AAnimal{
		Brain *brain;
	public:
		Dog();
		Dog( const Dog& dog);
		Dog& operator = ( const Dog& dog);
		~Dog();
		virtual void makeSound() const;
};

#endif
