/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Entrance.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Entrance::Entrance()
{
	name = "Entrance";
}

bool Entrance::item_needed()
{
	return(true);
}

void Entrance::print_item_needed()
{
	std::cout << std::endl;
	std::cout << "You need the Warden's Mask to enter this area!" << std::endl;
	std::cout << "The Warden's Mask is located in the ... Warden's Office" << std::endl;
	std::cout << std::endl;
}

std::string Entrance::get_name_of_item_needed()
{
	return("Warden's Office");
}