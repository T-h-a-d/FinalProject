/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Wardens_Office.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Wardens_Office::Wardens_Office()
{
	name = "Warden's Office";
	has_wardens_mask = true;
	wardens_mask = new Wardens_Mask;
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Wardens_Office::item_needed()
{
	return(true);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Wardens_Office::print_item_needed()
{
	std::cout << std::endl;
	std::cout << "You need the Warden's Key Card to access this area!" << std::endl;
	std::cout << "Hint: Inspect the Prison Yard ... the Warden is clumsy." << std::endl;
	std::cout << std::endl;
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Wardens_Office::get_name_of_item_needed()
{
	return("Key Card");
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Wardens_Office::inspect_room(Person* p)
{
	if(has_wardens_mask)
	{
		int user_choice;

		std::cout << std::endl;
		std::cout << "You look at the Warden's desk and see a strange mask on top of it" << std::endl;
		std::cout << "... It's a mask of the Warden's face" << std::endl;
		std::cout << "What kind of weird $#@^ is he into?" << std::endl;
		std::cout << std::endl;

		std::cout << "1. Pick up the Warden's Mask" << std::endl;
		std::cout << "2. Try to forget you ever saw it" << std::endl;

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

							//Add the Warden's mask to the backpack
							p->add_item(wardens_mask);

							//Wardens office no longer has the wardens mask
							has_wardens_mask = false;

							std::cout << std::endl;
							std::cout << "This might get you passed the guards at the Entrance!" << std::endl;
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
					//Add the Warden's mask to the backpack
					p->add_item(wardens_mask);

					//Wardens office no longer has the wardens mask
					has_wardens_mask = false;

					std::cout << std::endl;
					std::cout << "This might get you passed the guards at the Entrance!" << std::endl;
					std::cout << std::endl;
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
