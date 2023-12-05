#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <vector>
# include <sstream>

class PmergeMe
{
		Pmergeme(const Pmergeme& copy);
		PmergeMe& operator = (const Pmergeme& copy);
		Pmergeme();
		~Pmergeme();
	public:
		static void MergeInsertionSort(std::vector<int>& vec);
		static void InsertionSort(std::vector<int>& vec);
		static void Merge(std::vector<int>& vec1, std::vector<int>& vec2);
};

#endif
