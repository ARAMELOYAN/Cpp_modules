#ifndef CAT_HPP
# define CAT_HPP
# include "Brain.hpp"
# include "AAnimal.hpp"

class Cat: public AAnimal{
		Brain *brain;
	public:
		Cat();
		Cat( const Cat& cat);
		Cat& operator = ( const Cat& cat);
		~Cat();
		virtual void makeSound() const;
};
#endif
