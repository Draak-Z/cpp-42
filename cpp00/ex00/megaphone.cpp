#include <iostream>
#include <cctype>

int only_spaces_left(char *str, int i)
{
    while (str[++i])
        if (str[i] != ' ')
            return (0);
    return (1);
}

int main(int argc, char **argv)
{
	int i = 0, j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[++i])
		{
			j = 0;
            while (argv[i][j] == ' ')
                j++;
			while (argv[i][j])
            {
                if (only_spaces_left(argv[i], j - 1))
                    break ;
                if (argv[i][j] == ' ')
                {
                    while (argv[i][j] == ' ')
                        j++;
                    std::cout << ' ';
                }
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (0);
}