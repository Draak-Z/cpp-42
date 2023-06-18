#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(Intern const & src);
        virtual ~Intern(void);
        Intern & operator=(Intern const & rhs);

        AForm * makeForm(std::string name, std::string target);
};

#endif