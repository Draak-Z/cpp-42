#include "Form.hpp"

Form::Form(void) : _name("form"), _grade_to_sign(150), _grade_to_exec(150), _signed(false) {}

Form::Form(const std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _signed(false)
{
	if (_grade_to_sign < 1 || _grade_to_exec < 1)
		throw Form::GradeTooHighException();
	if (_grade_to_sign > 150 || _grade_to_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & rhs) : _name(rhs.getName()), _grade_to_sign(rhs.getGradeSign()), _grade_to_exec(rhs.getGradeExec()) {}

Form::~Form() {}

Form	&Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return (*this);
}

const std::string Form::getName(void) const { return (this->_name); }

int Form::getGradeSign(void) const { return (this->_grade_to_sign); }

int    Form::getGradeExec(void) const { return (this->_grade_to_exec); }

bool    Form::getSigned(void) const { return (this->_signed); }

void    Form::beSigned(Bureaucrat const & rhs)
{
    if (rhs.getGrade() <= this->getGradeSign())
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char* Form::GradeTooLowException::what() const throw() { return ("Grade too low"); }

std::ostream &  operator<<(std::ostream &o, Form const & rhs)
{
	o << "Form type : " << rhs.getName() << std::endl;
    o << "Sign status : " << rhs.getSigned() << std::endl;
    o << "Grade required to sign it : " << rhs.getGradeSign() << std::endl;
    o << "Grade required to execute it : " << rhs.getGradeExec() << std::endl;
	return (o);
}