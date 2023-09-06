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
		std::cout << BLUE << "Form copy constructor\n" << RESET;
	}
	return *this;
}

Form::Form(std::string name, bool sig, int rS, int rE):_name(name), _signed(sig),
	_requireSign(rS), _requireExec(rE)
{
	try
	{
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
		std::cout << BLUE << "Form parametric constructor\n" << RESET;
	}
	catch (std::exception & e){
		std::cout << BLUE << _name << " " << e.what() << RESET;
		if (rS > 150)
		{
			Form obj(name, sig, 150, rE);
			*this = obj;
		}
		else if (rS < 1)
		{
			Form obj(name, sig, 1, rE);
			*this = obj;
		}
		else if (rE > 150)
		{
			Form obj(name, sig, rS, 150);
			*this = obj;
		}
		else
		{
			Form obj(name, sig, rS, 1);
			*this = obj;
		}
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

unsigned char Form::getRS() const
{
	return _requireSign;
}

unsigned char Form::getRE() const
{
	return _requireExec;
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
	out << BLUE << "Hi. I Form. My\n_name - " << obj.getName()
		<< "\n_signed - " << obj.getSigned() << std::endl
		<< "_requireSign - " << obj.getRS() << std::endl
		<< "_requireExec - " << obj.getRE()	<< RESET << std::endl;
	return out;
}
