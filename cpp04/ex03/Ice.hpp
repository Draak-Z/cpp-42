#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{	
	public:
		Ice(void);
		Ice(Ice const &rhs);
		virtual ~Ice();

		Ice		&operator=(Ice const &rhs);

		Ice		*clone() const;
		void	use(ICharacter &target);
};
