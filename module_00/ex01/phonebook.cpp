#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
	std::cout<<"Phonebook created\n";
}

void PhoneBook::add(std::string fname, std::string lname, std::string nname,
		std::string phone, std::string secret)
{
	if (index == 8)
		index = 0;
	contact[index].f_name = fname;
	contact[index].l_name = lname;
	contact[index].n_name = nname;
	contact[index].phone = phone;
	contact[index].secret = secret;
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
		std::cout << contact[i].f_name;
		std::cout << contact[i].l_name;
		std::cout << contact[i].n_name << std::endl;
	}
}
