#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <fstream>

class RobotomyRequestForm: public AForm
{
		const std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator = (const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		void			makeDrillingNoice() const;
		virtual void	execute(Bureaucrat const& bur) const;
};
#endif
