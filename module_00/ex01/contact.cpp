#include "Contact.hpp"

void Contact::set_fname(std::string fname)
{
	f_name = fname;
}

void Contact::set_lname(std::string lname)
{
	l_name = lname;
}

void Contact::set_nname(std::string nname)
{
	n_name = nname;
}

void Contact::set_phone(std::string ph)
{
	phone = ph;
}

void Contact::set_secret(std::string sec)
{
	secret = sec;
}

void Contact::print(int index)
{
	std::cout << '\t' << std::setw(9) << index << ' ';
	if (f_name.length() > 9)
		std::cout << f_name.substr(0,9) << '.';
	else
		std::cout << std::setw(10) << f_name;
	if (l_name.length() > 9)
		std::cout << l_name.substr(0,9) << '.';
	else
		std::cout << std::setw(10) << l_name;
	if (n_name.length() > 9)
		std::cout << n_name.substr(0,9) << '.' << std::endl;
	else
		std::cout << std::setw(10) << n_name << std::endl;
}

void Contact::print_full(void)
{
	std::cout << "\t\t" << f_name << std::endl;
	std::cout << "\t\t" << l_name << std::endl;
	std::cout << "\t\t" << n_name << std::endl;
	std::cout << "\t\t" << phone<< std::endl;
	std::cout << "\t\t" << secret<< std::endl;
}
