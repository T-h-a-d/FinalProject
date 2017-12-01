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
#include "Person.hpp"
#include "Syringe.hpp"

class Hallway : public Space
{
private:
	Item* syringe;

public:
	Hallway(std::string);
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
};
#endif