#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const & rhs);
        Bureaucrat(const std::string &name, int grade);
        virtual ~Bureaucrat(void);

        Bureaucrat&         operator=(Bureaucrat const & rhs);
        const std::string   getName(void) const;
        int                 getGrade(void) const;
        void                incGrade(void);
        void                decGrade(void);
        void                signForm(Form &form) const;

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
};

std::ostream&  operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif