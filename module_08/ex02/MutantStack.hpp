#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <iterator>
# include <cstddef>
# include <stack>
# include <deque>
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	MutantStack(MutantStack& obj);
	MutantStack& operator = (MutantStack& obj);
public:
	MutantStack();
	~MutantStack();
	class iterator : public std::iterator<std::random_access_iterator_tag, T> {
		private:
			typename Container::iterator it;

		public:
			iterator(typename Container::iterator iter);
			// Implement necessary iterator methods
			iterator& operator++();
			iterator operator++(int);
			iterator& operator--();
			iterator operator--(int);
			T& operator*() const;
			bool operator!=(const iterator& other) const;
			bool operator==(const iterator& other) const;
	};

	// Provide begin and end functions
	iterator begin();
	iterator end();
};

# include "MutantStack.tpp"
#endif
