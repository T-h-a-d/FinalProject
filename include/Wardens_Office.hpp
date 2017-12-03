/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Entrance class. This class is derived from the Space 
** parent class and inherits all of its member variables and functions. It also overrides
** functions to check if there is a special item needed to enter the room, print the item
** needed to enter the room (if there is one), get the name of the item needed to enter 
** the room, and inspect the room. Inspecting the room allows the player to interact with
** the room. This class also has an Item pointer called wardens_mask which holds a 
** wardens_mask object, as well as a boolean has_wardens_mask to check if the user has 
** already put the wardens_mask in their backpack.
*******************************************************************************************/
#ifndef WARDENS_OFFICE_HPP
#define WARDENS_OFFICE_HPP
#include "Space.hpp"
#include "Person.hpp"
#include "Wardens_Mask.hpp"

class Wardens_Office : public Space
{
private:
	Item* wardens_mask;
	bool has_wardens_mask;

public:
	Wardens_Office();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
	~Wardens_Office();
};
#endif