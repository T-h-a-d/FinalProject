/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Header file for the Item class. This class represents the items that will
** be scattered throughout the prison and which the player will be able to pick up and
** interact with. The item class has the protected member variable, type, which represents
** the type of object which the item is. The Item class also contains a member function
** to return the type of item that it is, as well as a virtual destructor.
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