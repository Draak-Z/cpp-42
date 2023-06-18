#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void    iter(T const *array, size_t size, void function(T const &))
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

template<typename T>
void    print(T const & x) { std::cout << x << std::endl; }

#endif