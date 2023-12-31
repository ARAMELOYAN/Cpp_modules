#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern(const Intern& obj);
		Intern& operator = (const Intern& obj);
	public:
		Intern();
		~Intern();

		AForm* makeForm(std::string const& name, std::string const& target) const;
};
#endif
