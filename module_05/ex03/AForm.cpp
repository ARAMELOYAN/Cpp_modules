#include "AForm.hpp"

AForm::AForm()
	: _name("Default"), _requireSign(150), _requireExec(150)
{
	_signed = false;
	_executed = false;
}

AForm::AForm(const AForm& obj)
	: _name(obj._name), _signed(false),  _executed(false),
	_requireSign(obj._requireSign), _requireExec(obj._requireExec)
{
	std::cout << CYAN << "AForm copy constructor\n" << RESET;
}

AForm& AForm::operator = (const AForm& obj)
{
	if (this != &obj)
	{
		_signed = false;
		_executed = false;
		std::cout << CYAN << "AForm copy assignment operator\n" << RESET;
	}
	return *this;
}

AForm::AForm(std::string name, unsigned char rS, unsigned char rE)
	: _name(name), _signed(false), _executed(false), _requireSign(rS), _requireExec(rE)
{
	try
	{
		std::cout << CYAN << "AForm parametric constructor\n" << RESET;
		if (_requireSign > 150)
		{
			throw GradeTooLowException();
		}
		if (_requireSign < 1)
		{
			throw GradeTooHighException();
		}
		if (_requireExec > 150)
		{
			throw GradeTooLowException();
		}
		if (_requireExec < 1)
		{
			throw GradeTooHighException();
		}
	}
	catch (std::exception & e){
		std::cout << RED << _name << " " << e.what() << RESET;
	}
}

AForm::~AForm()
{
	std::cout << YELLOW << _name + " destructor\n" << RESET;
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

bool AForm::getExecuted() const
{
	return _executed;
}

void AForm::setExecuted() const
{
	_executed = true;
}

int AForm::getRS() const
{
	return _requireSign;
}

int AForm::getRE() const
{
	return _requireExec;
}

void AForm::beSigned(const Bureaucrat& bur)
{
	if (_signed)
		std::cout << BLUE << _name << " signed\n" << RESET;
	else
	{
		try
		{
			if (bur.getGrade() > _requireSign)
				throw GradeTooLowException();
			_signed = true;
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET;
		}
		bur.signForm(*this);
	}
}

const char* AForm::SignedException::what() const throw()
{
	return "Form Not signed";
}

const char* AForm::ExecutedException::what() const throw()
{
	return "Form executed";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is HIGH";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is LOW";
}

std::ostream& operator << (std::ostream& out, const AForm& obj)
{
	out << BLUE << "Hi. I am " << obj.getName()
		<< "\n_signed - " << obj.getSigned()
		<< "\n_executed - " << obj.getExecuted()
		<< "\n_requireSign - " << obj.getRS()
		<< "\n_requireExec - " << obj.getRE()	<< RESET << std::endl;
	return out;
}
