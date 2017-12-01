/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef INFIRMARY_HPP
#define INFIRMARY_HPP
#include "Space.hpp"
#include "Person.hpp"

class Infirmary : public Space
{
private:

public:
	Infirmary();
	bool item_needed();
	void print_item_needed();
	std::string get_name_of_item_needed();
};
#endif