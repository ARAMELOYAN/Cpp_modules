#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class AForm;

class Bureaucrat{
		const			std::string _name;
		unsigned char	_grade;
		Bureaucrat();
	public:
		Bureaucrat(const Bureaucrat& bur);
		Bureaucrat& operator = (const Bureaucrat& bur);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				increment();
		void				decrement();
		void				signForm(AForm const& form) const;
		void				executeForm(AForm const& form) const;

		class GradeTooHighException:public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException:public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream& out, const Bureaucrat &obj);
#endif
