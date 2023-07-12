#include "phonebook.hpp"
#include <unistd.h>

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
	std::cout<<"Phonebook created\n";
}

void PhoneBook::add()
{
	std::string fname, lname, nname, phone, secret;

	if (index == 8)
		index = 0;
	std::cout << "\tPlease input firstname\n\t\t";
	std::cin >> fname;
	std::cout << "\tPlease input lastneme\n\t\t";
	std::cin >> lname;
	std::cout << "\tPlease input nickname\n\t\t";
	std::cin >> nname;
	std::cout << "\tPlease input phone\n\t\t";
	std::cin >> phone;
	std::cout << "\tPlease input secret\n\t\t";
	std::cin >> secret;
	contact[index].set_fname(fname);
	contact[index].set_lname(lname);
	contact[index].set_nname(nname);
	contact[index].set_phone(phone);
	contact[index].set_secret(secret);
	index++;
	if (count < 8)
		count++;
}

void PhoneBook::search(void)
{
	int	i;

	i = 0;
	std::cout << std::setw(15) << "Index" << std::setw(15) << "First Name" << std::setw(15) << "Last Name" << std::setw(15) << "Nickname" << std::endl;
	while (i < count)
	{
		contact[i].print(i);
		i++;
	}
}
