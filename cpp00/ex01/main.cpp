#include <string>
#include "PhoneBook.hpp"

int	main(int argc, char *argv[])
{
	PhoneBook	phonebook;
	std::string command;

	if (argc > 1 || argv[1] != NULL)
    {
        std::cout << "Too many arguments" << std::endl;
        return (1);
    }
	while (1)
	{
		std::cout << "Input command ADD, SEARCH or EXIT: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phonebook.add_oldest_contact();
		else if (command == "SEARCH")
			phonebook.search();
	}
	return (0);
}
