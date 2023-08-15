#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = ""; 
	std::cout << CYAN << "Brain Default Constructor Called!\n" << RESET;
}

Brain::Brain( const Brain& br)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = br.ideas[i];
	std::cout << CYAN << "Brain Copy Constructor Called!\n" << RESET;
}

Brain& Brain::operator = ( const Brain& br)
{
	if (this == &br)
		return *this;
	for (int i = 0; i < 100; i++)
		ideas[i] = br.ideas[i];
	std::cout << CYAN << "Brain Copy Assignment operator Called!\n" << RESET;
	return *this;
}

Brain::~Brain()
{
	std::cout << CYAN << "Brain Destructor Called!\n" << RESET;
}

std::string Brain::getIdea(int index)
{
	return ideas[index];
}

void Brain::setIdea(std::string idea)
{
	int i;

	i = 0;
	while (ideas[i] != "")
		i++;
	ideas[i] = idea;
}
