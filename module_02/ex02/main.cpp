#include "Fixed.hpp"

int main( void ) {
Fixed a(2);
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed c = a / b;

std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << c << std::endl;
return 0;
}
