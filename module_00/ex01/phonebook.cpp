#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}

void PhoneBook::add(std::string fname, std::string lname, std::string nname)
{
	if (index == 8)
		index = 0;
	f_name[index] = fname;
	l_name[index] = lname;
	n_name[index] = nname;
	index++;
	if (count < 8)
		count++;
}

void PhoneBook::search(void)
{
	int	i;

	i = 0;
	std::cout << std::setw(10);
	std::cout << "Index";
	std::cout << "First Name";
	std::cout << "Last Name";
	std::cout << "Nickname" << std::endl;
	while (i < count)
	{
		std::cout << std::setw(10);
	   	std::cout << i;
	   	std::cout << f_name[i];
	   	std::cout << l_name[i];
	   	std::cout << n_name[i] << std::endl;
	}
}
