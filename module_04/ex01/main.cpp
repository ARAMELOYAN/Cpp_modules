#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animal[10];

	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Cat();
		animal[i + 5] = new Dog();
	}
	
	for (int i = 0; i < 10; i++)
		delete animal[i];
	return 0;
}
