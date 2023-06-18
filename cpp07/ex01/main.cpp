#include "iter.hpp"

class Awesome
{
	public:
		Awesome(void): _n( 42 ) { return; }
		int get(void) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<(std::ostream& o, Awesome const & rhs) { o << rhs.get(); return o; }

int	main(void)
{
	int			arrayInt[5] = {0, 1, 2, 3, 4};
	std::string	arrayStr[5] = {"foo", "bar", "baz", "qux", "quux"};
	char		arrayChar[5] = {'f', 'b', 'q', 'c', 'g'};
	Awesome		arrayA[5];

	iter<int>(arrayInt, 5, print);
	std::cout << std::endl;

	iter(arrayA, 5, print);
	std::cout << std::endl;

	iter<std::string>(arrayStr, 5, print);
	std::cout << std::endl;

	iter<char>(arrayChar, 5, print);
	std::cout << std::endl;

	return (0);
}