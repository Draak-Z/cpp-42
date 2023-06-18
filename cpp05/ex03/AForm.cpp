#include "AForm.hpp"

AForm::AForm(void) : _name("form"), _grade_to_sign(150), _grade_to_exec(150), _signed(false) {}

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _signed(false)
{
	if (_grade_to_sign < 1 || _grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	if (_grade_to_sign > 150 || _grade_to_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & rhs) : _name(rhs.getName()), _grade_to_sign(rhs.getGradeSign()), _grade_to_exec(rhs.getGradeExec()) {}

AForm::~AForm() {}

AForm	&AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return (*this);
}

const std::string AForm::getName(void) const { return (this->_name); }

int AForm::getGradeSign(void) const { return (this->_grade_to_sign); }

int    AForm::getGradeExec(void) const { return (this->_grade_to_exec); }

bool    AForm::getSigned(void) const { return (this->_signed); }

void    AForm::beSigned(Bureaucrat const & rhs)
{
    if (rhs.getGrade() <= this->getGradeSign())
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
}

void	AForm::tryExecute(Bureaucrat const &bureaucrat) const
{
	if (!this->getSigned())
		throw AForm::NotSigned();
	if (this->getGradeExec() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char* AForm::GradeTooLowException::what() const throw() { return ("Grade too low"); }

const char* AForm::NotSigned::what() const throw() { return ("The form is not signed"); }

const char* AForm::CantOpenFile::what() const throw() { return ("The file cannot be opened"); }

std::ostream &  operator<<(std::ostream &o, AForm const & rhs)
{
	o << "Form type : " << rhs.getName() << std::endl;
    o << "Sign status : " << rhs.getSigned() << std::endl;
    o << "Grade required to sign it : " << rhs.getGradeSign() << std::endl;
    o << "Grade required to execute it : " << rhs.getGradeExec() << std::endl;
	return (o);
}