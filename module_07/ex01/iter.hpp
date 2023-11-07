#ifndef ITER_HPP
# define ITER_HPP

template <class T>
void	t_pir(T& a);

template <class T, class P>
void	iter(T array[], int n, void (*func)(P));

#endif
