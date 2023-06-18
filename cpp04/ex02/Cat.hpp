#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat(void);
        Cat(Cat const &rhs);
        virtual ~Cat(void);
        Cat&    operator=(Cat const &rhs);

        void    makeSound(void) const;
        Brain *getBrain();

    private:
        Brain* _brain;
};

#endif