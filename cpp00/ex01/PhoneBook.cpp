#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	oldest_contact = 0;
}

void	PhoneBook::add_oldest_contact()
{
	oldest_contact %= 8;
	contacts[oldest_contact].create_contact();
	oldest_contact++;
	return ;
}

void	PhoneBook::search()
{
	int	index;

	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
		if (contacts[i].is_not_empty())
			contacts[i].search_trunked_contact(i);
	std::cout << "Input index of a contact: ";
	std::cin >> index;
	if (!index || (index < 0 || index > 8) || !(contacts[index - 1].is_not_empty()))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "No contact with that index!" << std::endl;
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		contacts[index - 1].display_contact();
	}
}