/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
#include "Backpack.hpp"
#include "Menu.hpp"
#include <iostream>

class Space;

class Person
{
protected:
	Backpack pack;
	Space* current_location;	//To keep track of the person's 
	std::string type;

	int dig_speed;
	bool under_influence;

public:
	std::string get_type();
	bool player_has_item(std::string);
	Space* get_location();
	void set_location(Space*);
	void add_item(Item*);
	bool kill_guard();
	bool backpack_full();
	void delete_backpack_item();
	void delete_specific_item(std::string);
	bool is_under_influence();
	void use_syringe();
	int get_dig_speed();
	void print_backpack_contents();
	virtual ~Person();

};
#endif