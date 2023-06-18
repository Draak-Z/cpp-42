#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("larva"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs.getName()), _grade(rhs.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs.getGrade();
	}
	return (*this);
}

const std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::incGrade(void)
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::decGrade(void)
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low"); }

void    Bureaucrat::signForm(Form &form) const
{
    if (form.getSigned() == true)
    {
        std::cout << form.getName() << " is already signed" << std::endl;
        return ;
    }
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signs the form " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &  operator<<(std::ostream &o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}