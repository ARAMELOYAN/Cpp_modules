#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

class PhoneBook {
		int			index;
		int			count;
		std::string f_name[8];
		std::string l_name[8];
		std::string n_name[8];
	public:
		PhoneBook();
		void	add(std::string fname, std::string lname, std::string nname);
		void	search();
}

#endif
