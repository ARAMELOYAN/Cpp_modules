#include "Phonebook.hpp"
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
	std::cout << "\tPlease input firstname\n\t";
	std::cin >> fname;
	contact[index].set_fname(fname);
	std::cout << "\tPlease input lastneme\n\t";
	std::cin >> lname;
	contact[index].set_lname(lname);
	std::cout << "\tPlease input nickname\n\t";
	std::cin >> nname;
	contact[index].set_nname(nname);
	std::cout << "\tPlease input phone\n\t";
	std::cin >> phone;
	contact[index].set_phone(phone);
	std::cout << "\tPlease input secret\n\t";
	std::cin >> secret;
	contact[index].set_secret(secret);
	index++;
	if (count < 8)
		count++;
}

void PhoneBook::search(void)
{
	std::string j;
	int			i;

	i = 0;
	std::cout << '\t' << std::setw(10) << "Index " << std::setw(10) << "First Name"
		<< std::setw(10) << "Last Name" << std::setw(10) << "Nickname"
		<< std::endl;
	while (i < count)
	{
		contact[i].print(i + 1);
		i++;
	}
	std::cout << "\tplease input contact index\n\t";
	std::cin >> j;
	if (j[1] || j[0] < '1' || j[0] > '9' || std::stoi(j) > count)
	{
		std::cout << "\tInvalid contact index\n";
		return ;
	}
	contact[std::stoi(j) - 1].print_full();
}
