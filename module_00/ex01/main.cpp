#include <iostream>

int main(int ac, char **av)
{
	PhoneBook	phone;
	std::string action;

	while (1)
	{
		std::cout << "Please input action\n\t";
		std::cin >> action;
		if (!strcmp(action, "ADD"))
			phone.add();
	}
}
