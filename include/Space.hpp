/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
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