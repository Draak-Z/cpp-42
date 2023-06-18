#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(Dog const &rhs);
        ~Dog(void);
        Dog&    operator=(Dog const &rhs);

        void    makeSound(void) const;
};

#endif