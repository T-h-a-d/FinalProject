/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Wardens_Office.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Wardens_Office::Wardens_Office()
{
	name = "Warden's Office";
}

bool Wardens_Office::item_needed()
{
	return(true);
}

void Wardens_Office::print_item_needed()
{
	std::cout << std::endl;
	std::cout << "You need the Warden's Key Card to access this area!" << std::endl;
	std::cout << "Hint: Look around the Prison Yard ... the Warden is clumsy." << std::endl;
	std::cout << std::endl;
}
