#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &rhs);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
		
		void					execute(Bureaucrat const &executor) const;
		std::string				getTarget(void) const;

	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif