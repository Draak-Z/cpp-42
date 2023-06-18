#include "Contact.hpp"

Contact::Contact()
{
	not_empty = false;
}

void	Contact::display_contact(void)
{
	std::cout << "first name:      " << first_name << std::endl;
	std::cout << "last name:       " << last_name << std::endl;
	std::cout << "nickname:        " << nickname << std::endl;
	std::cout << "phone number:    " << phone_number << std::endl;
	std::cout << "darkest secret:  " << darkest_secret << std::endl;
}

void	Contact::create_contact(void)
{
	std::cout << "Input contact's first name: " << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "Input contact's last name: " << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "Input contact's nickname: " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Input contact's phone number: " << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "Input contact's darkest secret: " << std::endl;
	std::getline(std::cin, darkest_secret);
	not_empty = true;
	return ;
}

bool	Contact::is_not_empty(void)
{
	return (not_empty);
}

void	Contact::format_field(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 9).append(".") << "|";
	else
		std::cout << std::right << std::setfill(' ') << std::setw(10) << str << "|";
	return ;
}

void	Contact::search_trunked_contact(int i)
{
	std::cout << "         " << i + 1 << "|";
	format_field(first_name);
	format_field(last_name);
	format_field(nickname);
	std::cout << std::endl;
	return ;
}