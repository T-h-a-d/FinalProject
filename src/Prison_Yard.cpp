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
	keycard = new Key_Card;
	has_keycard = true;
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Prison_Yard::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Prison_Yard::print_item_needed()
{

	
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Prison_Yard::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Prison_Yard::inspect_room(Person* p)
{
	if(has_keycard)
	{
		int user_choice;

		std::cout << std::endl;
		std::cout << "Another item on the ground!?" << std::endl;
		std::cout << "Hmm... this might get you into the Warden's Office" << std::endl;
		std::cout << std::endl;

		std::cout << "1. Pick up the Warden's Key Card" << std::endl;
		std::cout << "2. Leave the Key Card for someone else to find" << std::endl;

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
							p->add_item(keycard);

							//Prison Yard no longer has the key card
							has_keycard = false;

							std::cout << std::endl;
							std::cout << "Go check the Warden's Office" << std::endl;
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
					std::cout << "Go check the Warden's Office" << std::endl;
					std::cout << std::endl;
					
					p->add_item(keycard);

					//Prison Yard no longer has the key card
					has_keycard = false;
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