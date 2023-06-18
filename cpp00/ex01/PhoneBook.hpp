#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <limits>
#include <ios>

class	PhoneBook
{
	public:
		PhoneBook();
		void search(void);
		void add_oldest_contact(void);
	private:
		Contact contacts[8];
		int		oldest_contact;
};

#endif