#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const & src) { (void)src; }

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & rhs)
{
    (void)rhs;
    return (*this);
}

AForm * Intern::makeForm(std::string name, std::string target)
{
	AForm   *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm   *form = NULL;
	std::string request[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;

	while (i < 3 && request[i].compare(name))
		i++;
    if (i != 3)
	    form = forms[i];
    for (int j = 0; j < 3; j++)
        if (j != i)
            delete forms[j];
    if (form)
	    std::cout << "Intern creates " << form->getName() << std::endl;
    else
        std::cout << "Intern cannot create " << name << " because this format is unknown" << std::endl;
	return (form);
}