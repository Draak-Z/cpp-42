#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
    T   data = b;
	b = a;
	a = data;
}

template<typename T>
const T &max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

template<typename T>
const T &min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

#endif