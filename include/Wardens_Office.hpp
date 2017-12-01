/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef WARDENS_OFFICE_HPP
#define WARDENS_OFFICE_HPP
#include "Space.hpp"
#include "Person.hpp"

class Wardens_Office : public Space
{
private:

public:
	Wardens_Office();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
};
#endif