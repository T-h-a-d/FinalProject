/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Play_Jail_Escape.hpp"


int main()
{
	/**
	Backpack pack;
	Item* Radio = new Guard_Radio;
	Item* gun1 = new Gun;
	Item* spoon1 = new Spoon;

	pack.add_item(Radio);
	pack.add_item(gun1);
	pack.add_item(spoon1);

	pack.print_list();

	if(pack.at_capacity())
	{
		std::cout << "You already have 3 items in your bag." << std::endl;
	}

	pack.delete_item(2);

	pack.print_list();

	if(pack.item_in_backpack("Guard Radio"))
	{
		std::cout << "Item is in backpack." << std::endl;
	}

	else
	{
		std::cout << "Item is not in backpack." << std::endl;
	}
	**/

	Play_Jail_Escape play_game;

	play_game.start_game();

}