#include "PmergeMe.hpp"

void PmergeMe::MergeInsertionSort(std::vector<int>& vec)
{
	int n = vec.size();
	if (n < 20)
		InsertionSort(vec);
	else
	{
		std::vector<int> vec1(vec.begin(), vec.begin() + (n / 2) + 1);
		std::vector<int> vec2(vec.begin() + (n / 2) + 1, vec.end());
		MergeInsertionSort(vec1);
		MergeInsertionSort(vec2);
		Merge(vec1, vec2);
	}
}

void PmergeMe::InsertionSort(std::vector<int>& vec)
{

}
