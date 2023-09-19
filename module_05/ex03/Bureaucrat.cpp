#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):_name(obj._name), _grade(obj._grade)
{
	std::cout << CYAN << "Bureaucrat copy constructor\n" << RESET;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& obj)
{
	if (this != &obj)
	{
		_grade = obj._grade;
		std::cout << CYAN << "Bureaucrat copy constructor\n" << RESET;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade):_name(name), _grade(grade)
{
	try
	{
		if (_grade > 150)
		{
			_grade = 150;
			throw GradeTooLowException();
		}
		if (_grade < 1)
		{
			_grade = 1;
			throw GradeTooHighException();
		}
		std::cout << CYAN << "Bureaucrat parametric constructor\n" << RESET;
	}
	catch (std::exception & e){
		std::cout << CYAN << _name << " " << e.what() << RESET;
	}
}

void Bureaucrat::increment()
{
	try
	{
		if (_grade == 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch (std::exception & e){
		std::cout << RED << e.what() << RESET;
	}
}

void Bureaucrat::decrement()
{
	try
	{
		if (_grade == 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch (std::exception & e){
		std::cout << RED << e.what() << RESET;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << YELLOW << "Bureaucrat destructor\n" << RESET;
}

std::string const& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::signForm(AForm const& form) const
{
	if (form.getSigned())
		std::cout << GREEN << _name << " sign " << form.getName()
			<< RESET << "\n";
	else
		std::cout << RED << _name << " couldn't sign " << form.getName()
			<< " because grade is low\n" << RESET;
}

void Bureaucrat::executeForm(AForm const& form) const
{
	std::cout << GREEN << _name << " execute " << form.getName()
		<< RESET << "\n";
	form.setExecuted();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is HIGH\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is LOW\n";
}

std::ostream& operator << (std::ostream& out, const Bureaucrat& obj)
{
	out << GREEN << "Hi. I bureaucrat. My name is " << obj.getName()
		<< ". I have a grade " << obj.getGrade()
		<< RESET << std::endl;
	return out;
}
