#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bur("Burunduk", 9);
		AForm *form[3] = {
			new ShrubberyCreationForm("home"),
			new RobotomyRequestForm("Kuka"),
			new PresidentialPardonForm ("Aram")
		};
		for (int i = 0; i < 3; i++)
		{
			form[i]->beSigned(bur);
			bur.executeForm(*form[i]);
		}
		std::cout << *form[0];
		for (int i = 0; i < 3; i++)
			delete form[i];
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}
