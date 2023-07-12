#include "phonebook.hpp"
#include <iostream>

int main(int ac, char **av)
{
	std::string action;

	if (ac > 1 || av[1])
		return (0);
	PhoneBook	phone;

	while (1)
	{
		std::cout << "Please input action\n\t";
		std::cin >> action;
		if (!std::strcmp(const_cast<char *>(action.c_str()), "ADD"))
			phone.add();
		else if (!std::strcmp(const_cast<char *>(action.c_str()), "SEARCH"))
			phone.search();
		else if (!std::strcmp(const_cast<char *>(action.c_str()), "EXIT"))
			exit(0);
		else
			std::cout << "Invalid action\n";
	}
	return (0);
}
