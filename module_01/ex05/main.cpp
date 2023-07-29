#include "Harl.hpp"

int main(void)
{
	Harl vlo;
	vlo.complain("DEBUG");
	vlo.complain("INFO");
	vlo.complain("WARNING");
	vlo.complain("ERROR");
	vlo.complain("something else");
	return 0;
}
