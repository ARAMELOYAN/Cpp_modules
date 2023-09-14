#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << CYAN << "RobotomyRequestForm constructor\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	:AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << CYAN << "RobotomyRequestForm parametric constructor\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	:AForm(obj), _target(obj._target)
{
	std::cout << CYAN << "RobotomyRequestForm copy constructor\n" << RESET;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << _target + " destructor\n" << RESET;
}

void RobotomyRequestForm::makeDrillingNoice() const
{
	std::cout << GREEN << "Drrr~~~ DRRR~~~~ Draaaa~~~~~~\n" << RESET;
}

void RobotomyRequestForm::execute(Bureaucrat const& bur) const
{
	try
	{
		if (!getSigned())
			throw SignedException();
		if (bur.getGrade() > getRE())
			throw GradeTooLowException();
		if (getExecuted())
			throw ExecutedException();
		makeDrillingNoice();
		std::cout << GREEN << _target << " has been robotomised successfully 50%\n"
			<< RESET;
		bur.executeForm(*this);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET <<  std::endl;
	}
}
