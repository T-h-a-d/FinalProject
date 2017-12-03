/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
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