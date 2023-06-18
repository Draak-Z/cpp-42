#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{	
	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &rhs);
		virtual ~Character();

		Character	&operator=(Character const &rhs);

		const std::string	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	protected:
		static const int	_size = 4;
		AMateria			*_inventory[_size];
		std::string			_name;
};

#endif
