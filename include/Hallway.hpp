/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
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
};
#endif