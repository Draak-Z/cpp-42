#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog(void);
        Dog(Dog const &rhs);
        virtual ~Dog(void);
        Dog&    operator=(Dog const &rhs);

        void    makeSound(void) const;
        Brain *getBrain();

    private:
        Brain* _brain;
};

#endif