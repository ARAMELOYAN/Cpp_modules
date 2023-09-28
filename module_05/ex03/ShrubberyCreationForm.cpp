#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << CYAN << "ShrubberyCretionForm constructor\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	:AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << CYAN << "ShrubberyCretionForm parametric constructor\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	:AForm(obj), _target(obj._target)
{
	std::cout << CYAN << "ShrubberyCretionForm copy constructor\n" << RESET;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW << _target + " destructor\n" << RESET;
}

void ShrubberyCreationForm::writeTree() const
{
	std::ofstream out(_target + "_shrubbery");
	if (!out)
		return;
	out << "    /\\ " << std::endl;
    out << "   /**\\ " << std::endl;
    out << "  /****\\ " << std::endl;
    out << " /******\\ " << std::endl;
    out << "/********\\" << std::endl;
    out << "   ||||" << std::endl;
	out.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat& bur) const
{
	if (!getSigned())
		throw SignedException();
	if (bur.getGrade() > getRE())
		throw GradeTooLowException();
	if (getExecuted())
		throw ExecutedException();
	std::cout << GREEN << bur.getName() << " execute " << getName()
		<< RESET << "\n";
	writeTree();
	setExecuted();
}
