#include "Zombie.hpp"

int	main(int argc, char *argv[])
{
	Zombie *horde;
	std::string name;
	int N;

	if (argc != 3)
    {
        std::cout << "You must send 2 arguments, first is an integer and second is a name" << std::endl;
		return (1);
    }
	N = atoi(argv[1]);
    if (N <= 0)
    {
        std::cout << "first argument must be a positive integer" << std::endl;
        return (1);
    }
	name = argv[2];
	horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
			horde[i].announce();
	delete [] horde;
	return (0);
}