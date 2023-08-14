#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	const WrongAnimal* metas = new WrongAnimal();
	const WrongAnimal* k = new WrongDog();
	const WrongAnimal* l = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	k->makeSound(); //will output the cat sound!
	l->makeSound();
	metas->makeSound();
	return 0;
}
