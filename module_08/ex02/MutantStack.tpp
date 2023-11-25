#ifndef MTTANTSTACK_TPP
# define MTTANTSTACK_TPP
# include "MutantStack.hpp"

template <class T, class Container> 
MutantStack<T, Container>::MutantStack(): std::stack<T, Container>()
{
	std::cout<< GREEN"MutantStack constructor"RESET"\n";
}

template <class T, class Container> 
MutantStack<T, Container>::MutantStack(MutantStack&)
{
}

template <class T, class Container> 
MutantStack<T, Container>& MutantStack<T, Container>::operator = (MutantStack<T, Container>&)
{
}

template <class T, class Container> 
MutantStack<T, Container>::~MutantStack()
{
}

template <class T, class Container> 
MutantStack<T, Container>::iterator::iterator(typename Container::iterator iter) : it(iter)
{
}

template <class T, class Container> 
typename MutantStack<T,Container>::iterator& MutantStack<T, Container>::iterator::operator++()
{
	++it;
	return *this;
}

template <class T, class Container> 
typename MutantStack<T,Container>::iterator MutantStack<T, Container>::iterator::operator++(int)
{
	iterator copy(*this);
	++it;
	return copy;
}

template <class T, class Container> 
typename MutantStack<T,Container>::iterator& MutantStack<T, Container>::iterator::operator--()
{
	--it;
	return *this;
}

template <class T, class Container> 
typename MutantStack<T,Container>::iterator MutantStack<T, Container>::iterator::operator--(int)
{
	iterator copy(*this);
	--it;
	return copy;
}

template <class T, class Container> 
T& MutantStack<T, Container>::iterator::operator*() const
{
	return *it;
}

template <class T, class Container> 
bool MutantStack<T, Container>::iterator::operator!=(const iterator& other) const
{
	return it != other.it; 
}

template <class T, class Container> 
bool MutantStack<T, Container>::iterator::operator==(const iterator& other) const
{
	return it == other.it; 
}

template <class T, class Container> 
typename MutantStack<T,Container>::iterator MutantStack<T, Container>::begin()
{
	return iterator(this->c.begin());
}

template <class T, class Container> 
typename MutantStack<T,Container>::iterator MutantStack<T, Container>::end()
{
	return iterator(this->c.end());
};

#endif
