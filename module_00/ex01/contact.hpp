#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class	Contact{
		std::string f_name;
		std::string l_name;
		std::string n_name;
		std::string phone;
		std::string secret;
	public:
		Contact(std::string f_name,	std::string l_name,	std::string n_name,
				std::string phone, std::string secret);
		void print(void);
}
#endif

#include "contact.hpp"

Contact::Contact(std::string f_name, std::string l_name, std::string n_name,
		std::string phone, std::string secret)
{

}
