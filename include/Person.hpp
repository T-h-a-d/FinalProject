/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
#include "Backpack.hpp"
#include "Space.hpp"
#include <iostream>

class Person
{
protected:
	Backpack pack;
	Space* current_location;	//To keep track of the person's location


public:
	bool player_has_item(std::string);
	Space* get_location();
	void set_location(Space*);
	void add_item(Item*);
	virtual ~Person();

};
#endif