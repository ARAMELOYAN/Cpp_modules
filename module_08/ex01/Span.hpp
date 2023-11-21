#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <cstdlib>
# include <vector>
# include <ctime>
# include <algorithm>
# include <exception>
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

template <class T>
class Span{
		unsigned int maxNum;
		unsigned int currentNum;
		std::vector<T> span;
	public:
		Span();
		Span(unsigned int n = 0);
		Span& operator = (Span& obj);
		~Span();
		void addNumber(T num);
		void addNumber(T begin, T end);
		class SpanFull:std::exception{
			public:
				virtual const char* what() const throw();
		};
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

# include "Span.tpp"
#endif
