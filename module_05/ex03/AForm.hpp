#ifndef AFORM_HPP
# define AFORM_HPP
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

class AForm{
		const std::string 	_name;
		mutable bool 		_signed;
		mutable bool		_executed;
		const unsigned char _requireSign;
		const unsigned char _requireExec;
		AForm();
	public:
		AForm(const AForm& bur);
		AForm& operator = (const AForm& obj);
		AForm(std::string const& name, unsigned char rS, unsigned char rE);
		virtual ~AForm();

		std::string const& 	getName() const;
		bool 				getSigned() const;
		bool 				getExecuted() const;
		void 				setExecuted() const;
		int					getRS() const;
		int					getRE() const;
		void				beSigned(const Bureaucrat& bur);
		virtual void		execute(Bureaucrat const& bur) const = 0;

		class SignedException:public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class ExecutedException:public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException:public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException:public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream& out, const AForm &obj);
#endif
