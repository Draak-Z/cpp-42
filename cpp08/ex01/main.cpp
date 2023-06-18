#include "Span.hpp"

void    display(Span array)
{
    std::cout << "Display content : " << std::endl;
    std::vector<int> data = array.getData();
    for (std::vector<int>::const_iterator it = data.begin(); it < data.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int	main(void)
{
	srand(time(NULL));
	{
		std::cout << "-----Subject main-----" << std::endl;
		Span	sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
        display(sp);

		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "-----Exceptions-----" << std::endl;
		Span	sp = Span(4);

		sp.addNumber(5);
		try
		{
			std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{		
			std::cout << "Longest span : " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{	
			sp.addNumber(2652);
			sp.addNumber(-100);
			sp.addNumber(-876);
			sp.addNumber(12);
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		display(sp);
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "-----Big Span-----" << std::endl;
		std::vector<int>	v;
		Span				sp = Span(10000);

		for (int i = 1; i <= 10000; i++)
			v.push_back(rand());
		sp.addRangeNumber< std::vector<int> >(v.begin(), v.end());
		//display(sp);
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "-----Span Too Big-----" << std::endl;
		std::vector<int>	v;
		Span				sp = Span(10000);

		for (int i = 1; i <= 100000; i++)
			v.push_back(i);
		try
		{
			sp.addRangeNumber< std::vector<int> >(v.begin(), v.end());
			display(sp);
			std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span : " << sp.longestSpan() << std::endl << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	return (0);
}