#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template<typename T>
typename T::iterator easyfind(T &array, int n)
{
	typename T::iterator it;
	it = std::find(array.begin(), array.end(), n);
	if (it == array.end())
		throw std::runtime_error(std::string("No matches"));
	return (it);
}

#endif