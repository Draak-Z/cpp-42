#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &cure);
		virtual ~Cure();

		Cure	&operator=(Cure const &cure);

		Cure	*clone() const;
		void	use(ICharacter &target);
};
