#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

int	main(void)
{
	srand(time(NULL));
	std::cout << "----------Shrubbery Creation----------" << std::endl;
	ShrubberyCreationForm paper("Paper");
	Bureaucrat	drawer("Bob Ross", 137);
	Bureaucrat	other("John Doe", 150);

	other.executeForm(paper);
	other.signForm(paper);
	drawer.executeForm(paper);
	drawer.signForm(paper);
	std::cout << paper << std::endl;
	std::cout << drawer << std::endl;
	other.executeForm(paper);
	drawer.executeForm(paper);

	std::cout << std::endl << "----------Robotomy Request----------" << std::endl;
	RobotomyRequestForm human("Human");
	Bureaucrat	robot("robot", 45);
	Bureaucrat	other1("John Doe", 72);

	std::cout << robot << std::endl;
	std::cout << human << std::endl;
	robot.executeForm(human);
	other1.signForm(human);
	other1.executeForm(human);
	for (int i = 0; i < 10; i++)
		robot.executeForm(human);

	std::cout << std::endl << "----------Presidential Pardon----------" << std::endl;
	PresidentialPardonForm accused("Accused");
	Bureaucrat	president("Zafod Beeblebrox", 6);

	std::cout << president << std::endl;
	std::cout << accused << std::endl;
	president.executeForm(accused);
	president.signForm(accused);
	president.executeForm(accused);
	president.incGrade();
	president.executeForm(accused);

	return (0);
}