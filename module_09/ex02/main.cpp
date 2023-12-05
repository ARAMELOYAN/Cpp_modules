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
		std::cout << "vector before: ";
		PmergeMe<std::vector<int> >::print(vec);
		clock_t start_time = clock();
		PmergeMe<std::vector<int> >::MergeInsertionSort(vec);
		clock_t end_time = clock();
		std::cout << "vector after: ";
		PmergeMe<std::vector<int> >::print(vec);
		double elapsed_time_usec = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << std::fixed;
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector<int> "<< elapsed_time_usec << " seconds" << std::endl;
		std::cout << "deque before: ";
		PmergeMe<std::deque<int> >::print(deq);
		start_time = clock();
		PmergeMe<std::deque<int> >::MergeInsertionSort(deq);
		end_time = clock();
		std::cout << "deque after: ";
		PmergeMe<std::deque<int> >::print(deq);
		elapsed_time_usec = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque<int> "<< elapsed_time_usec << " seconds" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET "\n";
	}
}
