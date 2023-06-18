#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const & rhs);
        Bureaucrat(const std::string &name, int grade);
        virtual ~Bureaucrat(void);

        Bureaucrat&       operator=(Bureaucrat const & rhs);
        const std::string getName(void) const;
        int               getGrade(void) const;
        void              incGrade(void);
        void              decGrade(void);

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

    private:
        const std::string _name;
        int               _grade;
};

std::ostream&  operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif