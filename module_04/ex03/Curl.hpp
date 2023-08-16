#ifndef CURL_HPP
# define CURL_HPP
# include "AMateria.hpp"

class Curl{
	public:
		Curl();
		Curl( const Curl& curl );
		Curl& operator = ( const Curl& curl );
		virtual ~Curl();
		virtual AMateria* clone() const;
};
#endif
