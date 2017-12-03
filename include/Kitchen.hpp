/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Kitchen class. This class is derived from the Space 
** parent class and inherits all of its member variables and functions. It also overrides
** functions to check if there is a special item needed to enter the room, print the item
** needed to enter the room (if there is one), get the name of the item needed to enter 
** the room, and inspect the room. Inspecting the room allows the player to interact with
** the room. This class also has an Item pointer called spoon which holds a spoon object,
** as well as a boolean has_spoon to check if the user has already put the spoon in their
** backpack.
*******************************************************************************************/
#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Space.hpp"
#include "Person.hpp"

class Kitchen : public Space
{
private:
	Item* spoon;

	bool has_spoon;

public:
	Kitchen();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
	~Kitchen();
};
#endif