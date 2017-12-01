/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Prison_Yard.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Prison_Yard::Prison_Yard()
{
	name = "Prison Yard";
}

bool Prison_Yard::item_needed()
{
	return(false);
}

void Prison_Yard::print_item_needed()
{

	
}

std::string Prison_Yard::get_name_of_item_needed()
{
	return("");
}

void Prison_Yard::inspect_room(Person*)
{


}