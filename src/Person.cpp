/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Person.hpp"

Space* Person::get_location()
{
	return(current_location);
}

void Person::set_location(Space* loc)
{
	current_location = loc;
}

bool Person::player_has_item(std::string item)
{
	bool has_item = false;

	if(pack.item_in_backpack(item))
	{
		has_item = true;
	}

	else
	{
		has_item = false;
	}

	return(has_item);
}

void Person::add_item(Item* player_item)
{
	//Add item pointer to backpack
	pack->add_item(player_item);
}


Person::~Person()
{

	
}

