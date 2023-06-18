#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        Animal a;

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        a.makeSound();
        std::cout << std::endl;
        delete meta;
        delete j;
        delete i;
    }
    std::cout << std::endl;

	const WrongAnimal   *wrong = new WrongCat();
	std::cout << "wrong is " << wrong->getType() << std::endl;
	wrong->makeSound();
    std::cout << std::endl;
	delete wrong;
    std::cout << std::endl;
    const WrongCat  *cat = new WrongCat();
	std::cout << "cat is " << wrong->getType() << std::endl;
	cat->makeSound();
    std::cout << std::endl;
	delete cat;
    return 0;
}