/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Jail Cell class. This class is derived from the Space 
** parent class and inherits all of its member variables and functions. It also overrides
** functions to check if there is a special item needed to enter the room, print the item
** needed to enter the room (if there is one), get the name of the item needed to enter 
** the room, and inspect the room. Inspecting the room allows the player to interact with
** the room. This class also contains member variables to keep track of if the player has
** started digging a hole, if the whole is done being dug, how many minutes the player has
** dug for, and how many more minutes are needed to finish.
*******************************************************************************************/
#ifndef JAIL_CELL_HPP
#define JAIL_CELL_HPP
#include "Space.hpp"
#include "Person.hpp"

class Jail_Cell : public Space
{
private:
	bool hole;
	bool hole_is_done;
	float minutes_dug;
	float minutes_to_completion;
	float total_min_needed;

public:
	Jail_Cell();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
	bool done_digging();
};
#endif