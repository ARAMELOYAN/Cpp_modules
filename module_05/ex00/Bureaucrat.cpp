#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):_name(obj._name), _grade(obj._grade)
{
	std::cout << GREEN << "Bureaucrat copy constructor\n" << RESET;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& obj)
{
	if (this != &obj)
	{
		_grade = obj._grade;
		std::cout << GREEN << "Bureaucrat copy constructor\n" << RESET;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
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
	std::cout << GREEN << "Bureaucrat parametric constructor\n" << RESET;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << YELLOW << "Bureaucrat destructor" << RESET << std::endl;
}

std::string const& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::increment()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat rank must be below 0";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat rank must be above 151";
}

std::ostream& operator << (std::ostream& out, const Bureaucrat& obj)
{
	out << GREEN << "Hi. I bureaucrat. My name is " << obj.getName()
		<< ". I have a grade " << obj.getGrade()
		<< RESET << std::endl;
	return out;
}
