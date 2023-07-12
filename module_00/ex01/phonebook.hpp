#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include "contact.hpp"

class PhoneBook {
		int		index;
		int		count;
		Contact	contact[8];
	public:
		PhoneBook();
		void	add();
		void	search();
};

#endif
