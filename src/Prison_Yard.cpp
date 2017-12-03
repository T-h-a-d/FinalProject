/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Prison_Yard class. This class is 
** derived from the Space class and inherits all of its member variables and functions. 
** This class also overrides functions to check if there is a special item needed to enter
** the room, print the item needed to enter the room(if there is one), get the name of the
** item needed to enter the room, and inspect the room. Inspect the room allows the player
** to interact with the room. 
*******************************************************************************************/
#include "Prison_Yard.hpp"

/******************************************************************************************
** Constructor: Prison_Yard
** Description: Constructs a Prison Yard object. Initializes the name of the space to 
** "Prison Yard", dynamically allocates a new Key_Card item, and sets the has_keycard 
** boolean to true.
*******************************************************************************************/

Prison_Yard::Prison_Yard()
{
	name = "Prison Yard";
	keycard = new Key_Card;
	has_keycard = true;
}

/******************************************************************************************
** Function: item_needed
** Description: Boolean function which returns false becasue no items are needed to enter
** the Prison_Yard Space.
*******************************************************************************************/

bool Prison_Yard::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: print_item_needed
** Description: Prints nothing because no items are needed to enter the Prison_Yard space.
*******************************************************************************************/

void Prison_Yard::print_item_needed()
{

	
}

/******************************************************************************************
** Function: get_name_of_item_needed
** Description: Returns a string that represents the name of the item needed to enter
** the room. Note: The player does not need a specific item to enter this room.
*******************************************************************************************/

std::string Prison_Yard::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: inspect_room
** Description: Takes a person pointer as a parameter and asks the user if they would like
** to pick up the keycard object. If they say yes, then the function will check if their
** backpack is full. If it is not, the item is added to the backpack. If the backpack is
** full, then the user is asked if they would like to delete an item to make room for the
** keycard. If they say yes, then the user is asked which item they would like to delete.
** The function then changes the person's backpack based upon these choices.
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

/******************************************************************************************
** Destructor: Prison_Yard
** Description: Destroys a Prison_Yard object and deletes all of the previously dynamically 
** allocated objects.
*******************************************************************************************/

Prison_Yard::~Prison_Yard()
{
	//Delete the dynamically allocated item
	delete keycard;
}