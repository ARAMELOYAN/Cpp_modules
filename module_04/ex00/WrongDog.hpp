#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal{
	public:
		WrongDog();
		WrongDog( const WrongDog& dog);
		WrongDog& operator = ( const WrongDog& dog);
		~WrongDog();
		void makeSound() const;
};

#endif
