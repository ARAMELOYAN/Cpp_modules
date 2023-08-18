#ifndef MATERIASOUTCE_HPP
# define MATERIASOUTCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource{
		AMateria *materia[4];
	public:
		MateriaSource();
		MateriaSource( const MateriaSource& mat);
		MateriaSource& operator = ( const MateriaSource& mat);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* mat);
		virtual AMateria* createMateria(std::string const & type);
};
#endif

