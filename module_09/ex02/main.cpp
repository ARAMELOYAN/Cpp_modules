#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try	{
		if (ac < 2)
			throw std::runtime_error("invalid argument count");
		int	n = 1;
		double num;
		std::vector<int> vec;
		std::deque<int> deq;
		while (n < ac)
		{
			std::istringstream is(av[n]);
			while (is >> num)
			{
				if (num > INT_MAX || num < 0)
					throw std::runtime_error("invalid integer");
				vec.push_back(static_cast<int>(num));
				deq.push_back(static_cast<int>(num));
			}
			n++;	
		}
		if (vec.empty())
			throw std::runtime_error("Invalid argument");
		std::cout << GREEN "vector before: " RESET;
		PmergeMe<std::vector<int> >::print(vec);
		clock_t start_time = clock();
		PmergeMe<std::vector<int> >::MergeInsertionSort(vec);
		clock_t end_time = clock();
		std::cout << GREEN "vector after: " RESET;
		PmergeMe<std::vector<int> >::print(vec);
		double elapsed_time_usec = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << std::fixed;
		std::cout << GREEN "Time to process a range of " BLUE << vec.size() << GREEN " elements with std::vector<int> " BLUE << elapsed_time_usec << GREEN " seconds" RESET << std::endl;
		std::cout << GREEN "deque before: " RESET;
		PmergeMe<std::deque<int> >::print(deq);
		start_time = clock();
		PmergeMe<std::deque<int> >::MergeInsertionSort(deq);
		end_time = clock();
		std::cout << GREEN "deque after: " RESET;
		PmergeMe<std::deque<int> >::print(deq);
		elapsed_time_usec = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << GREEN "Time to process a range of " BLUE << deq.size() << GREEN " elements with std::deque<int> " BLUE << elapsed_time_usec << GREEN " seconds" RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET "\n";
	}
}
