#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		static const int	_size = 4;
		AMateria			*_inventory[_size];
		
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &materiaSource);
		virtual ~MateriaSource();

		MateriaSource	&operator=(MateriaSource const &materiaSource);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

#endif
