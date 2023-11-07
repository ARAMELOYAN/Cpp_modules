#include <iostream>
#include <iomanip>
#include "iter.hpp"

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << std::fixed << std::setprecision(1);
	iter(a, 10, ::t_pir<int>);
	iter(b, 10, ::t_pir<float>);
	return 0;
}

template <class T>
void	t_pir(T a)
{
	std::cout << a << '\n';
}

template <class T, class P>
void	iter(T array[], int n, void (*func)(P))
{
	for (int i = 0; i < n; i++)
		func(array[i]);
}
