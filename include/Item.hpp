/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>

class Item
{
protected:
	std::string type;


public:
	std::string get_type();
	virtual ~Item();


};
#endif