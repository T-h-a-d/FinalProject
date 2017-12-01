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
	int hole;
	int hours_dug;

public:
	Jail_Cell();
	void dig();
	bool check_if_spoon();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
};
#endif