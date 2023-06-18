#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &rhs);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
		
		void					execute(Bureaucrat const &executor) const;
		std::string				getTarget(void) const;

	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif