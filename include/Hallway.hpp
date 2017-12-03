/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Hallway class. This class is derived from the Space 
** parent class and inherits all of its member variables and functions. It also overrides
** functions to check if there is a special item needed to enter the room, print the item
** needed to enter the room (if there is one), get the name of the item needed to enter 
** the room, and inspect the room. Inspecting the room allows the player to interact with
** the room. This class also has Item pointers called syring, radio, and gun,  which hold 
** syringe, radio, and gun objects respectively, as well as a boolean variables to check
** if the user has taken the items out of the space and into their backpack.
*******************************************************************************************/
#ifndef HALLWAY_HPP
#define HALLWAY_HPP
#include <iostream>
#include "Space.hpp"
#include "Syringe.hpp"
#include "Person.hpp"

class Hallway : public Space
{
private:
	Item* syringe;
	Item* radio;
	Item* gun;

	bool has_syringe;
	bool has_radio;
	bool has_gun;

public:
	Hallway(std::string);
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
	void found_syringe(Person*);
	void found_radio(Person*);
	void found_gun(Person*);
	~Hallway();
};
#endif