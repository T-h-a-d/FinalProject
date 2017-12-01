/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Hallway.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Hallway::Hallway(std::string n)
{
	name = n;
	syringe = new Syringe;
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Hallway::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Hallway::print_item_needed()
{

	
}

std::string Hallway::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Hallway::inspect_room(Person* p)
{
	found_syringe(p);
}

void Hallway::found_syringe(Person* p)
{
	int user_choice;

	std::cout << "Wow this is a dirty ward. Do they ever clean up around here?" << std::endl;
	std::cout << "Oh look a syringe filled with PCP!" << std::endl;

	std::cout << "1. Pick up syringe" << std::endl;
	std::cout << "2. Leave that nasty thing where it belongs" << std::endl;

	Menu_Range_Int_Prompt("", user_choice, 1, 2);

	switch(user_choice)
	{
		case 1:
		{
			//If the inmates backpack is full allow them to choose an item to delete
			if(p->backpack_full())
			{
				int user_delete_choice;

				std::cout << "Your backpack is currently full ... " << std::endl;
				std::cout << "Would you like to delete an item from your backpack?" << std::endl;
				Make_Menu_Option("Yes", 1);
				Make_Menu_Option("No", 2);

				Menu_Range_Int_Prompt("", user_delete_choice, 1, 2);

				switch(user_delete_choice)
				{
					case 1:
					{
						//Choose an item to delete
						p->delete_backpack_item();

						//Add the syringe to the backpack
						p->add_item(syringe);

						std::cout << std::endl;
						std::cout << "I can't believe you actually picked that up ..." << std::endl;
						std::cout << "It's too dangerous to adminster yourself, but maybe you can get the nurse to do it" << std::endl;
						std::cout << std::endl;

						break;
					}

					case 2:
					{
						//Nothing happens because user chose not to delete item
						std::cout << "Good choice ... who knows what diseases you might have caught" << std::endl;
					}
				}
			}

			else
			{
				std::cout << std::endl;
				std::cout << "I can't believe you actually picked that up ..." << std::endl;
				std::cout << "It's too dangerous to adminster yourself, but maybe you can get the nurse to do it" << std::endl;
				std::cout << std::endl;

				p->add_item(syringe);
			}

			break;
		}

		case 2:
		{
			std::cout << "Good choice ... who knows what diseases you might have caught" << std::endl;
		}
	}
}
