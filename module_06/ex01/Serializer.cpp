#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << CYAN << "Serializer default constructor" << RESET << "\n";
}

Serializer::Serializer(const Serializer& obj)
{
	if (this != &obj)
		std::cout << CYAN << "Serializer copy constructor" << RESET << "\n";
}

Serializer::~Serializer()
{
	std::cout << YELLOW << "Serializer destructor" << RESET << "\n";
}

Serializer& Serializer::operator = (Serializer const& obj)
{
	if (this != &obj)
		std::cout << CYAN << "Serializer copy assignment operator" << RESET << "\n";
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
