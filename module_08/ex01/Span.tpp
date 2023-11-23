#ifndef SPAN_TPP
# define SPAN_TPP
# include "Span.hpp"

	template <class T>
Span<T>::Span()
{
	std::cout << GREEN"Span constructor"RESET"\n";
}

template <class T>
Span<T>::Span(unsigned int _n) : maxNum(_n), currentNum(0), span(std::vector<T>()) {
	std::cout << GREEN"Span parametric constructor"RESET"\n";
}

	template <class T>
Span<T>& Span<T>::operator = (Span& obj)
{
	if (*this == obj)
		return;
	delete span;
	span = std::vector<T>(obj.span);
	std::cout << GREEN"Span operator assignment"RESET"\n";
}

	template <class T>
Span<T>::~Span()
{
	span.clear();
	std::cout << GREEN"Span destructor"RESET"\n";
}

	template <class T>
void Span<T>::addNumber(T num)
{
	if (currentNum == maxNum)
		throw SpanFull();
	span.push_back(num);
	currentNum++;
	std::cout << GREEN"Number " << num <<" added in span"RESET"\n";
}

	template <class T>
void Span<T>::addNumber(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
	if (begin >= end)
	{
		std::cout << RED"Incorrect range of Numbers"RESET"\n";
		return ;
	}
	if (currentNum == maxNum)
		throw SpanFull();
	if (maxNum - currentNum < static_cast<unsigned int>(end - begin))
	{
		std::cout << RED"Span cant include this numbers"RESET"\n";
		return ;
	}
	for (; begin < end; begin++)
	{
		span.push_back(*begin);
		currentNum++;
	}
	std::cout << GREEN"Numbers added in span"RESET"\n";
}

	template <class T>
const char* Span<T>::SpanFull::what() const throw()
{
	return RED"ERROR: Span is full"RESET"\n";
}

template <class T>
unsigned int Span<T>::shortestSpan() const
{
	if (span.empty())
		return 0;
	if (span.size() == 1)
		return *span.begin();
	std::vector<T> vec(span);
	std::sort (vec.begin(), vec.end());
	typename std::vector<T>::iterator itvec = vec.begin() + 1;
	unsigned int spanmin = *itvec - *(itvec - 1);
	for (; itvec < vec.end(); itvec++)
		if (spanmin > static_cast<unsigned int>(*itvec - *(itvec - 1)))
			spanmin = *itvec - *(itvec - 1);
	return spanmin;
}

template <class T>
unsigned int Span<T>::longestSpan() const
{
	if (span.empty())
		return 0;
	if (span.size() == 1)
		return *span.begin();
	return (*std::max_element(span.begin(),span.end()) -
			*std::min_element(span.begin(), span.end()));
}
#endif
