#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>

class	Contact{
		std::string f_name;
		std::string l_name;
		std::string n_name;
		std::string phone;
		std::string secret;
	public:
		void set_fname(std::string fname);
		void set_lname(std::string lname);
		void set_nname(std::string nname);
		void set_phone(std::string phon);
		void set_secret(std::string sec);
		void print(int i);
};

#endif
