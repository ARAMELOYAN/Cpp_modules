#ifndef EASYFIND_TPP
# define EASYFIND_TPP
# include "easyfind.hpp"
# include <vector>
# include <iterator>

template <class T>
int easyfind(T& container, int val)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
	{
		throw std::exception();
	}
	return std::distance(container.begin(), it);
}

#endif
