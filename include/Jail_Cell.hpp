/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef JAIL_CELL_HPP
#define JAIL_CELL_HPP
#include "Space.hpp"
#include "Person.hpp"

class Jail_Cell : public Space
{
private:
	bool hole;
	bool hole_is_done;
	float minutes_dug;
	float minutes_to_completion;
	float total_min_needed;

public:
	Jail_Cell();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
	bool done_digging();
};
#endif