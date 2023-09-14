#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm: public AForm
{
		const std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator = (const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		void			pardon() const;
		virtual void	execute(Bureaucrat const& bur) const;
};
#endif
