
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <ios>

class Contact
{
	public:
		Contact();
		bool	is_not_empty(void);
		void	display_contact(void);
		void	search_trunked_contact(int i);
		void	create_contact(void);
	private:
		void	format_field(std::string str);
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		bool		not_empty;
};

#endif