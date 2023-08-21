#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat{
		const std::string name;
		unsigned char grade;
	public:
		const std::string getName() const;
		int getGrade() const;
