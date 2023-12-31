#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(Cat const &rhs);
        ~Cat(void);
        Cat&    operator=(Cat const &rhs);

        void    makeSound(void) const;
};

#endif