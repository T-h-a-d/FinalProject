/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Entrance class. This class is 
** derived from the Space class and inherits all of its member variables and functions. 
** This class also overrides functions to check if there is a special item needed to enter
** the room, print the item needed to enter the room(if there is one), get the name of the
** item needed to enter the room, and inspect the room. Inspect the room allows the player
** to interact with the room. 
*******************************************************************************************/
#include "Entrance.hpp"

/******************************************************************************************
** Constructor: Entrance
** Description: Constructs and Entrance object and sets the name equal to "Entrance".
*******************************************************************************************/

Entrance::Entrance()
{
	name = "Entrance";
}

/******************************************************************************************
** Function: item_needed
** Description: Boolean function which returns true because the Warden's Mask is needed to
** enter the Entrance of the jail.
*******************************************************************************************/

bool Entrance::item_needed()
{
	return(true);
}

/******************************************************************************************
** Function: print_item_needed
** Description: Prints the item that is needed to enter the Entrance along with a 
** description of where to find it.
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
** Function: get_name_of_item_needed
** Description: Returns a string that represents the name of the item needed to enter
** the room.
*******************************************************************************************/

std::string Entrance::get_name_of_item_needed()
{
	return("Warden's Mask");
}

/******************************************************************************************
** Function: inspect_room
** Description: This entrance room is not able to be inspected, as once the player enters 
** the room, they win the game
*******************************************************************************************/

void Entrance::inspect_room(Person*)
{


}