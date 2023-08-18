#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		materia[i] = nullptr;
	}
	std::cout << BLUE << "MateriaSource default constructor called\n" << RESET;
}

MateriaSource::MateriaSource( const MateriaSource& mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (mat.materia[i])
			materia[i] = mat.materia[i]->clone();
		else
			materia[i] = nullptr;
	}
	std::cout << BLUE << "MateriaSource copy constructor called\n" << RESET;
}

MateriaSource& MateriaSource::operator = ( const MateriaSource& mat)
{
	if (this == &mat)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (mat.materia[i])
			materia[i] = mat.materia[i]->clone();
		else
			materia[i] = nullptr;
	}
	std::cout << BLUE << "MateriaSource copy assignment operator called\n"
		<< RESET;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete materia[i];
	}
	std::cout << BLUE << "MateriaSource destructor called\n";
}

void MateriaSource::learnMateria(AMateria* mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			continue;
		materia[i] = mat->clone();
		break;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	}
	return 0;
}
