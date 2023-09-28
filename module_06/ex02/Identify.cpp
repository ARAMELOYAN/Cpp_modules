#include "Identify.hpp"

Identify::Identify()
{
	std::cout << CYAN << "Identify default constructor" << RESET << "\n";
}

Identify::Identify(const Identify& obj)
{
	if (this != &obj)
		std::cout << CYAN << "Identify copy constructor" << RESET << "\n";
}

Identify::~Identify()
{
	std::cout << YELLOW << "Identify destructor" << RESET << "\n";
}

Identify& Identify::operator = (const Identify& obj)
{
	if (this != &obj)
		std::cout << CYAN << "Identify copy assignment operator" << RESET << "\n";
	return *this;
}

Base* Identify::generate(void)
{
	int	num;

	srand(time(NULL));
	num = rand() % 3 + 1;
	switch(num)
	{
		case 1:
			return new A();
		case 2:
			return new B();
		case 3:
			return new C();
		default:
			return 0;
	}
}

void Identify::identify(Base* p)
{
	A* Aptr = dynamic_cast<A*>(p);
	if (Aptr)
	{
		delete p;
		std::cout << GREEN"class A pointer"RESET"\n";
		return ;
	}
	B* Bptr = dynamic_cast<B*>(p);
	if (Bptr)
	{
		delete p;
		std::cout << GREEN"class B pointer"RESET"\n";
		return ;
	}
	C* Cptr = dynamic_cast<C*>(p);
	if (Cptr)
	{
		delete p;
		std::cout << GREEN"class C pointer"RESET"\n";
		return ;
	}
}

void Identify::identify(Base& p)
{
	try
	{
		A Aptr = dynamic_cast<A&>(p);
		std::cout << GREEN"class A Referance"RESET"\n";
		return ;
	}
	catch (std::exception &)
	{}
	try
	{
		B Bptr = dynamic_cast<B&>(p);
		std::cout << GREEN"class B Referance"RESET"\n";
		return ;
	}
	catch (std::exception &)
	{}
	try
	{
		C Cptr = dynamic_cast<C&>(p);
		std::cout << GREEN"class C Referance"RESET"\n";
		return ;
	}
	catch (std::exception &)
	{}
}
