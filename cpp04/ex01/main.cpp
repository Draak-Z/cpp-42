#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        Dog	dog1;
        Brain *b = dog1.getBrain();
        std::string *in = b->getIdeas();
        std::cout << std::endl;
        in[0] = "food";
        std::cout << "|" << in[0] << "|" << std::endl;
        std::cout << std::endl;
        {
            Dog	dog2 = dog1;
            std::cout << std::endl;
            b = dog2.getBrain();
            in = b->getIdeas();
            std::cout << "|" << in[0] << "|" << std::endl;
            in[0] = "no food";
            std::cout << "|" << in[0] << "|" << std::endl;
            std::cout << std::endl;
        }
        b = dog1.getBrain();
        in = b->getIdeas();
        std::cout << std::endl;
        std::cout << "|" << in[0] << "|" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << std::endl;
        Cat	cat1;
        Brain *b = cat1.getBrain();
        std::string *in = b->getIdeas();
        std::cout << std::endl;
        in[0] = "sleep";
        std::cout << "|" << in[0] << "|" << std::endl;
        std::cout << std::endl;
        {
            Cat	cat2(cat1);
            std::cout << std::endl;
            b = cat2.getBrain();
            in = b->getIdeas();
            std::cout << "|" << in[0] << "|" << std::endl;
            in[0] = "no sleep";
            std::cout << "|" << in[0] << "|" << std::endl;
            std::cout << std::endl;
        }
        b = cat1.getBrain();
        in = b->getIdeas();
        std::cout << std::endl;
        std::cout << "|" << in[0] << "|" << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    Brain br;

	Animal *array[4];
	for(int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		if (i % 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	std::cout << std::endl << std::endl;
	for(int i = 0; i < 4; i++)
		array[i]->makeSound();
    std::cout << std::endl;
	for(int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		delete array[i];
	}
	std::cout << std::endl;
}