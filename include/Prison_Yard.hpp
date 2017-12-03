/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Prison Yard class. This class is derived from the Space 
** parent class and inherits all of its member variables and functions. It also overrides
** functions to check if there is a special item needed to enter the room, print the item
** needed to enter the room (if there is one), get the name of the item needed to enter 
** the room, and inspect the room. Inspecting the room allows the player to interact with
** the room. This class also has an Item pointer called keycard which holds a keycard object,
** as well as a boolean has_keycard to check if the user has already put the keycard in their
** backpack.
*******************************************************************************************/
#ifndef PRISON_YARD_HPP
#define PRISON_YARD_HPP
#include "Space.hpp"
#include "Person.hpp"
#include "Key_Card.hpp"

class Prison_Yard : public Space
{
private:
	Item* keycard;
	bool has_keycard;

public:
	Prison_Yard();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
	~Prison_Yard();
};
#endif