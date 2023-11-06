#include <iostream>
#include <iomanip>

template <class T>
void	t_pir(T a)
{
	std::cout << a << '\n';
}

template <class T>
void	iter(T array[], int n, void (*func)(T))
{
	for (int i = 0; i < n; i++)
		func(array[i]);
}

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << std::fixed << std::setprecision(1);
	iter(a, 10, ::t_pir);
	iter(b, 10, ::t_pir);
	return 0;
}
