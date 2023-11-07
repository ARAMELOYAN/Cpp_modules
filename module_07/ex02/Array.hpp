#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"
# include <exception>

template <class T> class Array
{
		unsigned int _n;
		T* _array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& obj);
		Array<T>& operator = (const Array<T>& obj);
		~Array();
		T&	operator [](int n);
		const T&	operator [](int n) const;
		unsigned int	size() const;
};

#include "Array.tpp"
#endif
