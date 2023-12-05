#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try	{
		if (ac < 2)
			throw std::runtime_error("invalid argument count");
		int	n = 1;
		double num;
		std::vector<int> vec;
		while (n <= ac)
		{
			std::istringstream is(av[n]);
			while (is >> num)
			{
				if (num > INT_MAX || num < 0)
					throw std::runtime_error("invalid integer");
				vec.push_back(static_cast<int>(num));
			}
			n++;	
		}
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET "\n";
	}
	PmergeMe::MergeInsertionSort(vec);
}
