#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RRF", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RRF", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs)
{
	this->_target = rhs.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	this->_target = rhs.getTarget();
	return (*this);
}

std::ostream &  operator<<(std::ostream &o, RobotomyRequestForm const & rhs)
{
	o << "Form type : " << rhs.getName() << std::endl;
    o << "Sign status : " << rhs.getSigned() << std::endl;
    o << "Grade required to sign it : " << rhs.getGradeSign() << std::endl;
    o << "Grade required to execute it : " << rhs.getGradeExec() << std::endl;
    o << "Target : " << rhs.getTarget() << std::endl;
	return (o);
}

std::string	RobotomyRequestForm::getTarget(void) const { return (this->_target); }

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    this->tryExecute(executor);
	std::cout << "*Zouyyyyyyyy Vrrrrrrrr* ";
	int ret = rand() % 2;
	if (ret)
		std::cout << "The target : " << this->_target << " was robotomized" << std::endl;
	else
		std::cout << "The target : " << this->_target << " was not robotomized" << std::endl;
}