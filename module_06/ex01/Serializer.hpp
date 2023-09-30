#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include "Data.hpp"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class Serializer
{
		Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator = (const Serializer& obj);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
#endif
