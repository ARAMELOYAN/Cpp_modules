#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
class Identify
{
		Identify(const Identify& obj);
		Identify& operator = (const Identify& obj);
	public:
		Identify();
		~Identify();
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};
#endif
