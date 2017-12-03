/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef PRISON_YARD_HPP
#define PRISON_YARD_HPP
#include "Space.hpp"
#include "Person.hpp"
#include "Key_Card.hpp"

class Prison_Yard : public Space
{
private:
	Item* keycard;
	bool has_keycard;

public:
	Prison_Yard();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
	void inspect_room(Person*);
	~Prison_Yard();
};
#endif