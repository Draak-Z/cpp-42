  
#include <iostream>
#include <ctime>
#include "Class.hpp"

Base    *generate(void)
{
	int	nb;

	nb = std::rand() % 3;
	if (nb == 0)
		return (new A());
	if (nb == 1)
		return (new B());
	return (new C());
}

void    identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) {}
}

int	main(void)
{
	Base	*p;
	srand(time(NULL));

	p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}