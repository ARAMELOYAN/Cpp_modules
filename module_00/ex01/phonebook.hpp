#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>

typedef struct	s_contact
{
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string phone;
	std::string secret;
}				t_contact;

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
