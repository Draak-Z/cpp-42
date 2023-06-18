#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iomanip>

int	main(void)
{
	Bureaucrat	pres("President", 1);
	Intern		exploitedIntern;
	AForm		*forms[4];

	srand(time(NULL));
	forms[0] = exploitedIntern.makeForm("shrubbery creation", "Art");
	forms[1] = exploitedIntern.makeForm("robotomy request", "Bender");
	forms[2] = exploitedIntern.makeForm("presidential pardon", "Accused");
	forms[3] = exploitedIntern.makeForm("formular", "A38");

	for (int i = 0; i < 4; i++)
	{
		if (forms[i])
		{
			pres.signForm(*(forms[i]));
			pres.executeForm(*(forms[i]));
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete forms[i];
	return (0);
}