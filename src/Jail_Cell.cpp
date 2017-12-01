/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Jail_Cell.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Jail_Cell::Jail_Cell()
{
	name = "Jail Cell";
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Jail_Cell::dig()
{



}

bool Jail_Cell::item_needed()
{
	return(false);
}

void Jail_Cell::print_item_needed()
{


}

std::string Jail_Cell::get_name_of_item_needed()
{
	return("");
}


/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

/**
bool Jail_Cell::check_if_spoon(Person* p)
{	
	bool spoon = false;

	for(int i = 0; i < size of backpack; i++)
	{
		if(person->backpack->get_front() == "Spoon")
		{
			spoon = true;
		}

		person->backpack->next();
	}

	return(spoon);
}
**/