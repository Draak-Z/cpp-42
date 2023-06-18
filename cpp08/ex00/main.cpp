#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <iomanip>
#include <ctime>
#include "easyfind.hpp"

static void	display(int a)
{
	std::cout << a << " ";
}

template<typename T>
void	tests(std::string const name)
{
	std::cout << "-----" << name << "-----" << std::endl;
	int	array[10];
    int n = 5;
    typename T::iterator it;
	for (int i = 0; i < 10; i++)
		array[i] = std::rand() % 100;
    std::cout << std::endl << "Content of " << name << "<int>" << std::endl;
	T	lst(array, array + 10);
	std::for_each(lst.begin(), lst.end(), display);
	std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Looking for the value at array[" << n << "]" << std::endl;
    try
    {
        it = easyfind(lst, array[n]);
        std::cout << "The value found at array[" << n << "] is " << *it << std::endl << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
    n = 9;
    std::cout << "Looking for the value at array[" << n << "]" << std::endl;
    try
    {
        it = easyfind(lst, array[n]);
        std::cout << "The value found at array[" << n << "] is " << *it << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
    n = -1;
    std::cout << "Looking for the value at array[" << n << "]" << std::endl;
    try
    {
        it = easyfind(lst, array[n]);
        std::cout << "The value found at array[" << n << "] is " << *it << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
    n = 22;
    std::cout << "Looking for the value at array[" << n << "]" << std::endl;
    try
    {
        it = easyfind(lst, array[n]);
        std::cout << "The value found at array[" << n << "] is " << *it << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
}

int	main(void)
{
	srand(time(NULL));

	tests< std::vector<int> >("vector");
	tests< std::deque<int> >("deque");
	tests< std::list<int> >("list");
	
	return (0);
}