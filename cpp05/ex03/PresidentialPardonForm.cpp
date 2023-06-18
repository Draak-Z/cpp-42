#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PPF", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PPF", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs)
{
	this->_target = rhs.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	this->_target = rhs.getTarget();
	return (*this);
}

std::ostream &  operator<<(std::ostream &o, PresidentialPardonForm const & rhs)
{
	o << "Form type : " << rhs.getName() << std::endl;
    o << "Sign status : " << rhs.getSigned() << std::endl;
    o << "Grade required to sign it : " << rhs.getGradeSign() << std::endl;
    o << "Grade required to execute it : " << rhs.getGradeExec() << std::endl;
    o << "Target : " << rhs.getTarget() << std::endl;
	return (o);
}

std::string	PresidentialPardonForm::getTarget(void) const { return (this->_target); }

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    this->tryExecute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}