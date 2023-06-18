#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		
		void					execute(Bureaucrat const &executor) const;
		std::string				getTarget(void) const;

	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif