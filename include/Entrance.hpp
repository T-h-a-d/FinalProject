/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Entrance class. This class is derived from the Space 
** parent class and inherits all of its member variables and functions. It also overrides
** functions to check if there is a special item needed to enter the room, print the item
** needed to enter the room (if there is one), get the name of the item needed to enter 
** the room, and inspect the room. Inspecting the room allows the player to interact with
** the room.
*******************************************************************************************/
#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP
#include "Space.hpp"
#include "Person.hpp"

class Entrance : public Space
{
private:


public:
	Entrance();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
};
#endif