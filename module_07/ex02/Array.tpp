#ifndef ARRAY_TPP
# define ARRAY_TPP
template <class T>
Array<T>::Array():_n(0),_array(new T[0])
{
	std::cout << GREEN"constructor Array"RESET"\n";
}

template <class T>
Array<T>::Array(unsigned int n):_n(n),_array(new T[_n])
{
	std::cout << GREEN"parametric constructor Array"RESET"\n";
}

template <class T>
Array<T>::Array(Array<T> const& obj):_n(obj._n),_array(new T[obj._n])
{
	for (unsigned int i = 0; i < _n; i++)
		_array[i] = obj._array[i];
	std::cout << GREEN"copy constructor Array"RESET"\n";
}

template <class T>
Array<T>& Array<T>::operator = (const Array<T>& obj)
{
	delete [] _array;
	_n = obj._n;
	_array = new T[_n];
	for (unsigned int i = 0; i < _n; i++)
		_array[i] = obj._array[i];
	std::cout << GREEN"assignment operator Array"RESET"\n";
	return (*this);
}

template <class T>
T& Array<T>::operator [] (int n)
{
	if (static_cast<unsigned int>(n) >= _n)
		throw std::overflow_error(RED"index out of size Array"RESET);
	if (n < 0)
		throw std::underflow_error(RED"index can't be negative number"RESET);
	return _array[n];
}

template <class T>
const T& Array<T>::operator [] (int n) const
{
	if (static_cast<unsigned int>(n) >= _n)
		throw std::overflow_error(RED"index out of size Array"RESET);
	if (n < 0)
		throw std::underflow_error(RED"index can't be negative number"RESET);
	return _array[n];
}

template <class T>
Array<T>::~Array()
{
	delete [] _array;
	std::cout << GREEN"destructor Array"RESET"\n";
}

template <class T>
unsigned int Array<T>::size() const
{
	return (_n);
}

#endif
