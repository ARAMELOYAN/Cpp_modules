#ifndef CAT_HPP
# define CAT_HPP
# include "Brain.hpp"
# include "Animal.hpp"

class Cat: public Animal{
		Brain *brain;
	public:
		Cat();
		Cat( const Cat& cat);
		Cat& operator = ( const Cat& cat);
		~Cat();
		void makeSound() const;
};
#endif
