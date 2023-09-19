#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
		const std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		void			writeTree() const;
		virtual void	execute(Bureaucrat const& bur) const;
};
#endif
