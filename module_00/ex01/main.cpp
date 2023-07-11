#include "phonebook.hpp"
#include <iostream>

int main(int ac, char **av)
{
	PhoneBook	phone;
	std::string action;

	if (ac > 1 || av[1])
		return (0);
	while (1)
	{
		std::cout << "Please input action\n\t";
		std::cin >> action;
		if (!std::strcmp(const_cast<char *>(action.c_str()), "ADD"))
			std::cout<< std::setw(10) << "HELLO\n";
	}
	return (0);
}
