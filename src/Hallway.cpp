/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Hallway class. This class is 
** derived from the Space class and inherits all of its member variables and functions. 
** This class also overrides functions to check if there is a special item needed to enter
** the room, print the item needed to enter the room(if there is one), get the name of the
** item needed to enter the room, and inspect the room. Inspect the room allows the player
** to interact with the room. 
*******************************************************************************************/
#include "Hallway.hpp"

/******************************************************************************************
** Constructor: Hallway
** Description: Constructs a Hallway object and sets its name based on the string parameter,
** n. This is because there are multiple different Hallways in the game, and it is important
** to tell the difference between the 3. The constructor then dynamically allocates three
** objects, a syringe, a guard_radio, and a gun. It also sets the has_item boolean variable
** to true for all three objects.
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
** Function: item_needed
** Description: Boolean function which returns false because no items are needed to enter
** the Hallway.
*******************************************************************************************/

bool Hallway::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: print_item_needed
** Description: Prints nothing because no items are needed.
*******************************************************************************************/

void Hallway::print_item_needed()
{

	
}

/******************************************************************************************
** Function: get_name_of_item_needed
** Description: Returns a string that represents the name of the item needed to enter
** the room. Note: The player does not need a specific item to enter this room.
*******************************************************************************************/

std::string Hallway::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: inspect_room
** Description: This function takes a Person pointer as a parameter and uses it to call one
** of three functions which are chosen randomly. The player is only allowed to pick up one
** item of a certain type per hallway they encounter, and found_item keeps track of which
** items have been picked up.
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
** Function: found_syringe
** Description: Takes a person pointer as a parameter and asks the user if they would like
** to pick up the syringe object. If they say yes, then the function will check if their
** backpack is full. If it is not, the item is added to the backpack. If the backpack is
** full, then the user is asked if they would like to delete an item to make room for the
** syringe. If they say yes, then the user is asked which item they would like to delete.
** The function then changes the person's backpack based upon these choices.
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
** Function: found_radio
** Description: Takes a person pointer as a parameter and asks the user if they would like
** to pick up the radio object. If they say yes, then the function will check if their
** backpack is full. If it is not, the item is added to the backpack. If the backpack is
** full, then the user is asked if they would like to delete an item to make room for the
** radio. If they say yes, then the user is asked which item they would like to delete.
** The function then changes the person's backpack based upon these choices.
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
** Function: found_gun
** Description: Takes a person pointer as a parameter and asks the user if they would like
** to pick up the gun object. If they say yes, then the function will check if their
** backpack is full. If it is not, the item is added to the backpack. If the backpack is
** full, then the user is asked if they would like to delete an item to make room for the
** gun. If they say yes, then the user is asked which item they would like to delete.
** The function then changes the person's backpack based upon these choices.
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

/******************************************************************************************
** Destructor: Hallway
** Description: Destroys a Hallway object and deletes all of the previously dynamically 
** allocated objects.
*******************************************************************************************/

Hallway::~Hallway()
{
	//Delete all of the dynamically allocated items
	delete syringe;
	delete radio;
	delete gun;
}
