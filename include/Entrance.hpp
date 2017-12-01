/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP
#include "Space.hpp"
#include "Person.hpp"

class Entrance : public Space
{
private:


public:
	Entrance();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
};
#endif