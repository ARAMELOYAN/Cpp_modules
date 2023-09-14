#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):_name(obj._name), _grade(obj._grade)
{
	std::cout << RED << "Bureaucrat copy constructor\n" << RESET;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& obj)
{
	if (this != &obj)
	{
		_grade = obj._grade;
		std::cout << RED << "Bureaucrat copy constructor\n" << RESET;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
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
		std::cout << RED << "Bureaucrat parametric constructor\n" << RESET;
	}
	catch (std::exception & e){
		std::cout << RED << _name << " " << e.what() << RESET;
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
	std::cout << RED << "Bureaucrat destructor\n" << RESET;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
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
	out << RED << "Hi. I bureaucrat. My name is " << obj.getName()
		<< ". I have a grade " << obj.getGrade()
		<< RESET << std::endl;
	return out;
}
