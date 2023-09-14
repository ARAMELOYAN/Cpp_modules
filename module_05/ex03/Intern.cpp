#include "Intern.hpp"

Intern::Intern()
{
	std::cout << CYAN << "Intern default constructor\n" << RESET;
}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}

Intern& Intern::operator = (const Intern& obj)
{
	if (this != &obj)
		;
	return *this;
}

Intern::~Intern()
{
	std::cout << YELLOW << "Intern destructor\n" << RESET;
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
	int iname;

	iname = (name == "shrubbery creation") + (name == "robotomy request") * 2 +
		(name == "presidential pardon") * 3;
	switch(iname)
	{
		case 1:
			std::cout << GREEN << "Intern creates shrubbery creation form\n" << RESET;
			return new ShrubberyCreationForm(target);
		case 2:
			std::cout << GREEN << "Intern creates robotomy request form\n" << RESET;
			return new RobotomyRequestForm(target);
		case 3:
			std::cout << GREEN << "Intern creates presidential pardon form\n" << RESET;
			return new PresidentialPardonForm(target);
	}
	std::cout << RED << "You are trying to create a form that doesn't exist\n" << RESET;
	return NULL;
}
