#include "Span.hpp"

int main()
{
	try
	{
		srand(time(NULL));
		Span<int> sp2 = Span<int>(10000);
		for (int i = 1; i <= 10000; ++i)
			sp2.addNumber(rand() % 100000);
		std::cout << "Short span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Long span: " << sp2.longestSpan() << std::endl;
		Span<int> sp = Span<int>(7);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::vector<int> vec(2, 100);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const Span<int>::SpanFull& e)
	{
		std::cout << e.what();
	}
	return 0;
}
