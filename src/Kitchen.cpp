/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Kitchen class. This class is 
** derived from the Space class and inherits all of its member variables and functions. 
** This class also overrides functions to check if there is a special item needed to enter
** the room, print the item needed to enter the room(if there is one), get the name of the
** item needed to enter the room, and inspect the room. Inspect the room allows the player
** to interact with the room. 
*******************************************************************************************/
#include "Kitchen.hpp"

/******************************************************************************************
** Constructor: Kitchen
** Description: Constructs a kitchen object. Initializes the name of the space to "Kitchen",
** dynamically allocates a new Spoon item, and sets the has_spoon boolean to true.
*******************************************************************************************/

Kitchen::Kitchen()
{
	name = "Kitchen";
	spoon = new Spoon;
	has_spoon = true;
}

/******************************************************************************************
** Function: item_needed
** Description: Boolean function which returns false because no items are needed to enter 
** the kitchen area.
*******************************************************************************************/

bool Kitchen::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: print_item_needed
** Description: Prints nothing because no items are needed to enter the Kitchen space.
*******************************************************************************************/

void Kitchen::print_item_needed()
{

	
}

/******************************************************************************************
** Function: get_name_of_item_needed
** Description: Returns a string that represents the name of the item needed to enter
** the room. Note: The player does not need a specific item to enter this room.
*******************************************************************************************/

std::string Kitchen::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: inspect_room
** Description: Takes a person pointer as a parameter and asks the user if they would like
** to pick up the spoon object. If they say yes, then the function will check if their
** backpack is full. If it is not, the item is added to the backpack. If the backpack is
** full, then the user is asked if they would like to delete an item to make room for the
** spoon. If they say yes, then the user is asked which item they would like to delete.
** The function then changes the person's backpack based upon these choices.
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

/******************************************************************************************
** Destructor: Kitchen
** Description: Destroys a Kitchen object and deletes all of the previously dynamically 
** allocated objects.
*******************************************************************************************/

Kitchen::~Kitchen()
{
	//Deleted the dynamically allocated item
	delete spoon;
}

