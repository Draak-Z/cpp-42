#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("SCF", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("SCF", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm(rhs)
{
    this->_target = rhs.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	this->_target = rhs.getTarget();
	return (*this);
}

std::ostream &  operator<<(std::ostream &o, ShrubberyCreationForm const & rhs)
{
	o << "Form type : " << rhs.getName() << std::endl;
    o << "Sign status : " << rhs.getSigned() << std::endl;
    o << "Grade required to sign it : " << rhs.getGradeSign() << std::endl;
    o << "Grade required to execute it : " << rhs.getGradeExec() << std::endl;
    o << "Target : " << rhs.getTarget() << std::endl;
	return (o);
}

std::string	ShrubberyCreationForm::getTarget(void) const { return (this->_target); }

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->AForm::tryExecute(executor);
    std::ofstream   file((this->_target + "_shrubbery").c_str());
	if (file.is_open() == false)
		throw CantOpenFile();
	file << "              v .   ._, |_  .," << std::endl;
    file << "       \'-._\\/  .  \\ /    |/_" << std::endl;
    file << "           \\\\  _\\, y | \\//" << std::endl;
    file << "     _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
    file << "       \'7-,--.\'._||  / / ," << std::endl;
    file << "       /\'     \'-.\'./ / |/_.\'" << std::endl;
    file << "                 |    |//" << std::endl;
    file << "                 |_    /   " << std::endl;
    file << "                 |-   |" << std::endl;
    file << "                 |   =|" << std::endl;
    file << "                 |    |" << std::endl;
	file << "----------------/ ,  . \\----------------" << std::endl;
	file.close();
}