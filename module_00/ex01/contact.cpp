#include "contact.hpp"

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
	std::cout << std::setw(15) << index << std::setw(15) << f_name << std::setw(15) << l_name << std::setw(15) << n_name << std::endl;
}
