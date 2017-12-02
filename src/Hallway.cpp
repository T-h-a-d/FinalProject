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
	radio = new Guard_Radio;
	gun = new Gun;

	//Hallway only has 3 items and they can only be picked up once
	has_syringe = true;
	has_radio = true;
	has_gun = true;
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
	int inspect_room_choice = rand() % 3 + 1;

	switch(inspect_room_choice)
	{
		case 1:
		{
			if(has_syringe == false)
			{
				std::cout << std::endl;
				std::cout << "There doesn't seem to be anything here" << std::endl;
				std::cout << std::endl;
			}

			else
			{
				found_syringe(p);
			}

			break;
		}

		case 2:
		{	
			if(has_radio == false)
			{
				std::cout << std::endl;
				std::cout << "There doesn't seem to be anything here" << std::endl;
				std::cout << std::endl;
			}

			else
			{
				found_radio(p);
			}

			break;
		}

		case 3:
		{
			if(has_gun == false)
			{
				std::cout << std::endl;
				std::cout << "There doesn't seem to be anything here" << std::endl;
				std::cout << std::endl;
			}

			else
			{
				found_gun(p);
			}
		}
	}
	
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

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

						//Hallway no longer has the syringe
						has_syringe = false;

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

				//Hallway no longer has the syringe
				has_syringe = false;
			}

			break;
		}

		case 2:
		{
			std::cout << "Good choice ... who knows what diseases you might have caught" << std::endl;
		}
	}
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Hallway::found_radio(Person* p)
{
	int user_choice;

	std::cout << "A guard dropped his radio!" << std::endl;
	std::cout << "You might be able to find out the guard's location with this ..." << std::endl;

	std::cout << "1. Pick up radio" << std::endl;
	std::cout << "2. Leave radio on the ground" << std::endl;

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

						//Add the radio to the backpack
						p->add_item(radio);

						//Hallway no longer has the radio
						has_radio = false;

						std::cout << std::endl;
						std::cout << "You will now be able to see the location of the guard after each round" << std::endl;
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
				std::cout << "You will now be able to see the location of the guard after each round" << std::endl;
				std::cout << std::endl;

				p->add_item(radio);

				//Hallway no longer has the radio
				has_radio = false;
			}

			break;
		}

		case 2:
		{
			
		}
	}
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Hallway::found_gun(Person* p)
{
	int user_choice;

	std::cout << "These guards really are terrible at their jobs."  << std::endl;
	std::cout << "How could you forget to pick up your gun from the floor?!" << std::endl;

	std::cout << "1. Pick up gun" << std::endl;
	std::cout << "2. Leave the gun" << std::endl;

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

						//Add the radio to the backpack
						p->add_item(gun);

						//Hallway no longer has the gun
						has_gun = false;

						std::cout << std::endl;
						std::cout << "The guard doesn't stand a chance against stopping you now" << std::endl;
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
				std::cout << "The guard doesn't stand a chance against stopping you now" << std::endl;
				std::cout << std::endl;

				p->add_item(gun);

				//Hallway no longer has the gun
				has_gun = false;
			}

			break;
		}

		case 2:
		{
			
		}
	}
}
