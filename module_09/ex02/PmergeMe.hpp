#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <ctime>
# include <cstdlib>
# include <sstream>
# include <sys/time.h>

template <class Container = std::vector<int> >
class PmergeMe
{
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator = (const PmergeMe& copy);
	PmergeMe();
	~PmergeMe();
	public:
	static void MergeInsertionSort(Container& vec)
	{
		int n = vec.size();
		if (n < 20)
			InsertionSort(vec);
		else
		{
			Container vec1(vec.begin(), vec.begin() + (n / 2) + 1);
			Container vec2(vec.begin() + (n / 2) + 1, vec.end());
			MergeInsertionSort(vec1);
			MergeInsertionSort(vec2);
			Merge(vec, vec1, vec2);
		}
	}
	static void InsertionSort(Container& vec)
	{
		typename Container::iterator it = vec.begin() + 1;
		typename Container::iterator jt;
		while (it < vec.end())
		{
			jt = it;
			while (jt > vec.begin())
			{
				if (*jt > *(jt - 1))
					break ;
				swap(jt--);
			}
			++it;
		}
		it = vec.begin();
	}
	static void Merge(Container& vec, Container& vec1, Container& vec2)
	{
		vec.erase(vec.begin(), vec.end());
		typename Container::iterator it1 = vec1.begin();
		typename Container::iterator it2 = vec2.begin();
		while (it1 < vec1.end() && it2 < vec2.end())
		{
			if (*it1 < *it2)
				vec.push_back(*(it1++));
			else
				vec.push_back(*(it2++));
		}
		if (it1 == vec1.end())
			while (it2 < vec2.end())
				vec.push_back(*(it2++));
		else
			while (it1 < vec1.end())
				vec.push_back(*(it1++));
	}
	static void swap(typename Container::iterator it)
	{
		int tmp;
		tmp = *it;
		*it = *(it - 1);
		*(it - 1) = tmp;
	}
	static void print(Container& vec)
	{
		int i = 0;
		typename Container::iterator it = vec.begin();
		std::cout << BLUE;
		while (it < vec.end() && ++i < 6)
			std::cout << *it++ << " ";
		std::cout << RESET;
		if (it < vec.end())
			std::cout << "[...]\n";
		else
			std::cout << "\n";
	}
};

#endif
