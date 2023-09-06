#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class Bureaucrat;

class Form{
		const std::string 	_name;
		bool 				_signed;
		const unsigned char _requireSign;
		const unsigned char _requireExec;
		Form();
	public:
		Form(const Form& bur);
		Form& operator = (const Form& bur);
		Form(std::string name, bool sin, unsigned char rS, unsigned char rE);
		~Form();

		const std::string 	getName() const;
		bool 				getSigned() const;
		int					getRS() const;
		int					getRE() const;
		void				beSigned(Bureaucrat bur);

		class GradeTooHighException:public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException:public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream& out, const Form &obj);
#endif
