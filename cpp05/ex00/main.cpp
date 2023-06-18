#include "Bureaucrat.hpp"

void	testBasic(void)
{
	Bureaucrat  salaryman("salaryman", 7);

	std::cout << salaryman << std::endl;
    for (int i = 0; i < 3; i++)
	    salaryman.decGrade();
	std::cout << salaryman << std::endl;
    for (int i = 0; i < 9; i++)
	    salaryman.incGrade();
	std::cout << salaryman << std::endl;
	salaryman.incGrade();
}

int	main(void)
{
	try
	{
		testBasic();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	salaryman("salaryman", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	salaryman("salaryman", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}