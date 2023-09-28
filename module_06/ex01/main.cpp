#include "Serializer.hpp"

int main()
{
	Data *ptr = new Data;

	ptr->name = "Aram";
	ptr->age = 28;
	std::cout << ptr << "\n";
	std::cout << ptr->name << "\n";
	std::cout << ptr->age << "\n";
	ptr = Serializer::deserialize(Serializer::serialize(ptr));
	std::cout << ptr << "\n";
	std::cout << ptr->name << "\n";
	std::cout << ptr->age << "\n";
	delete ptr;
	return 0;
}
