#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &rhs);
        virtual ~WrongAnimal(void);
        WrongAnimal&    operator=(WrongAnimal const &rhs);

        void    makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string _type;
};

#endif