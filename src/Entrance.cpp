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

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Entrance::item_needed()
{
	return(true);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Entrance::print_item_needed()
{
	std::cout << std::endl;
	std::cout << "You need the Warden's Mask to enter this area!" << std::endl;
	std::cout << "How are you going to get past the entrance guard without a disguise?!" << std::endl;
	std::cout << "Hint: The Warden's Mask is located in the Warden's Office" << std::endl;
	std::cout << std::endl;
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Entrance::get_name_of_item_needed()
{
	return("Warden's Office");
}

/******************************************************************************************
** Function: inspect_room
** Description: This entrance room is not able to be inspected, as once the player enters 
** the room, they win the game
*******************************************************************************************/

void Entrance::inspect_room(Person*)
{


}