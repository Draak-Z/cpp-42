#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(const std::string name, int grade_to_sign, int grade_to_exec);
		AForm(const AForm &form);
		virtual ~AForm();

		AForm	&operator=(const AForm &form);

		const std::string	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat const & rhs);
        virtual void        execute(Bureaucrat const & executor) const = 0;
		void				tryExecute(Bureaucrat const &bureaucrat) const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
		
		class NotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class CantOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &o, const AForm &form);

#endif