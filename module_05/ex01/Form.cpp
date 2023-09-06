#include "Form.hpp"

Form::Form(): _name("Default"), _requireSign(150), _requireExec(150)
{
	_signed = false;
}

Form::Form(const Form& obj):_name(obj._name), _signed(obj._signed), 
	_requireSign(obj._requireSign), _requireExec(obj._requireExec)
{
	std::cout << BLUE << "Form copy constructor\n" << RESET;
}

Form& Form::operator = (const Form& obj)
{
	if (this != &obj)
	{
		_signed = obj._signed;
		std::cout << BLUE << "Form copy assignment operator\n" << RESET;
	}
	return *this;
}

Form::Form(std::string name, bool sig, unsigned char rS, unsigned char rE):_name(name), _signed(sig),
	_requireSign(rS), _requireExec(rE)
{
	try
	{
		std::cout << BLUE << "Form parametric constructor\n" << RESET;
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
		std::cout << BLUE << _name << " " << e.what() << RESET;
	}
}

Form::~Form()
{
	std::cout << BLUE << "Form destructor\n" << RESET;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getRS() const
{
	return _requireSign;
}

int Form::getRE() const
{
	return _requireExec;
}

void Form::beSigned(Bureaucrat bur)
{
	if (_signed)
		std::cout << BLUE << _name << " signed\n" << RESET;
	else
	{
		try
		{
			if (bur.getGrade() > _requireSign)
				throw GradeTooHighException();
			_signed = true;
		}
		catch (std::exception &e)
		{
			std::cout << BLUE << e.what() << RESET;
		}
		bur.signForm(*this);
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is HIGH\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is LOW\n";
}

std::ostream& operator << (std::ostream& out, const Form& obj)
{
	out << BLUE << "Hi. I am " << obj.getName()
		<< "\n_signed - " << obj.getSigned() << std::endl
		<< "_requireSign - " << obj.getRS() << std::endl
		<< "_requireExec - " << obj.getRE()	<< RESET << std::endl;
	return out;
}
