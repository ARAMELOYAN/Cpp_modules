#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

typedef struct	s_contact
{
	std::string f_name[8];
	std::string l_name[8];
	std::string n_name[8];
	std::string phone_number[8];
	std::string darkness_secret[8];
}
class PhoneBook {
		int		index;
		int		count;
		t_contact 	contact[8];
	public:
		PhoneBook();
		void	add(std::string fname, std::string lname, std::string nname, std::string phone_number, std::string darkness_secret);
		void	search();
}

#endif
