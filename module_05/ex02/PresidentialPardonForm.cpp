#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << CYAN << "PresidentialPardonForm constructor\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	:AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << CYAN << "PresidentialPardonForm parametric constructor\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	:AForm(obj), _target(obj._target)
{
	std::cout << CYAN << "PresidentialPardonForm copy constructor\n" << RESET;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YELLOW << _target + " destructor\n" << RESET;
}

void PresidentialPardonForm::pardon() const
{
	std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& bur) const
{
	try
	{
		if (!getSigned())
			throw signedException();
		if (bur.getGrade() > getRE())
			throw GradeTooLowException();
		pardon();
		bur.executeForm(*this);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET <<  std::endl;
	}
}
