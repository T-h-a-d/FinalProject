/********************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Space class. This class contains 4 member variables,
** right, left, top, and bottom which are Space pointers and correspond to the adjacent
** Spaces to the current Space. These Space pointers will be used to connect different 
** types of Space into a 2-d like structure. The Space class also has a member variable,
** name, to keep track of the name of the space. The Space class has member functions to,
** get the name of a space, set an adjacent space, get an adjacent space, print room 
** options for the player and get the choice, randomly move the guard. The Space class also
** has virtual member functions to check if a player is done_digging (overriden by Jail_Cell),
** check if a certain item is needed to enter a Space, print text about the item needed to 
** enter a Space, get the name of the item needed to enter the Space, and inspect a room.
** The class also has a virtual destructor.
*********************************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include "Menu.hpp"
#include <cstdlib>

class Person;

class Space
{

protected:
	Space* right;
	Space* left;
	Space* top;
	Space* bottom;
	std::string name;


public:
	std::string get_name();
	void set_adjacent_spaces(std::string, Space*);
	Space* get_adjacent_space(std::string);
	std::string room_options_player();
	std::string room_options_guard();
	virtual bool done_digging();
	virtual bool item_needed() = 0;
	virtual void print_item_needed() = 0;
	virtual std::string get_name_of_item_needed() = 0;
	virtual void inspect_room(Person*) = 0;
	virtual ~Space();

};
#endif