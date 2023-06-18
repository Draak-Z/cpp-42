#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form        form("A38", 10, 4);
	Bureaucrat  salaryman("salaryman", 11);

	std::cout << form << std::endl;
	std::cout << salaryman << std::endl;
	
	salaryman.signForm(form);
	salaryman.incGrade();
	salaryman.signForm(form);
	salaryman.signForm(form);

	std::cout << std::endl << form << std::endl;

	return (0);
}