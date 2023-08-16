#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AAnimal *animal[10];

	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Cat();
		animal[i]->makeSound();
		animal[i + 5] = new Dog();
		animal[i + 5]->makeSound();
	}
	
	for (int i = 0; i < 9; i++)
		delete animal[i];
	return 0;
}
