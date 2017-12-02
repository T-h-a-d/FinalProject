/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Kitchen.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Kitchen::Kitchen()
{
	name = "Kitchen";
	spoon = new Spoon;
	has_spoon = true;
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Kitchen::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Kitchen::print_item_needed()
{

	
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Kitchen::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Kitchen::inspect_room(Person* p)
{
	if(has_spoon)
	{
		int user_choice;

		std::cout << "You see something shimmer in the corner of the kitchen..." << std::endl;
		std::cout << "It's a spoon!" << std::endl;
		std::cout << "Hey, you could use this to dig a hole in your cell" << std::endl;
		std::cout << "It might be too slow though ..." << std::endl;

		std::cout << "1. Pick up spoon" << std::endl;
		std::cout << "2. Leave spoon on the ground" << std::endl;

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
							p->add_item(spoon);

							//Kitchen no longer has the spoon
							has_spoon = false;

							std::cout << std::endl;
							std::cout << "This might be more handy if you had some performance enhancing drugs ..." << std::endl;
							std::cout << std::endl;

							break;
						}

						case 2:
						{
							//Nothing happens because user chose not to delete item
						}
					}
				}

				else
				{
					std::cout << std::endl;
					std::cout << "This might be more handy if you had some performance enhancing drugs ..." << std::endl;
					std::cout << std::endl;

					p->add_item(spoon);

					//Kitchen no longer has the spoon
					has_spoon = false;
				}

				break;
			}

			case 2:
			{
	      //Nothing happens
			}
		}
	}

	else
	{
		std::cout << std::endl;
		std::cout << "There doesn't seem to be anything here" << std::endl;
		std::cout << std::endl;
	}
}


