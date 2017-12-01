/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Person.hpp"
#include "Space.hpp"

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
	pack.add_item(player_item);
}

bool Person::backpack_full()
{
	if(pack.at_capacity())
	{
		return(true);
	}

	else
	{
		return(false);
	}
}

void Person::delete_backpack_item()
{
	int user_delete_choice;
	int items_in_pack = pack.print_list();

	std::cout << std::endl;
	std::cout << "Enter the number of the item you would like to delete." << std::endl;
	std::cout << std::endl;

	Menu_Range_Int_Prompt("", user_delete_choice, 1, items_in_pack);

	pack.delete_item(user_delete_choice);
}

bool Person::kill_guard()
{


}


Person::~Person()
{

	
}

