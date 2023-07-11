#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include "contact.hpp"

class PhoneBook {
		int		index;
		int		count;
		t_contact 	contact[8];
	public:
		PhoneBook();
		void	add(std::string fname, std::string lname, std::string nname, std::string phone_number, std::string darkness_secret);
		void	search();
};

#endif
