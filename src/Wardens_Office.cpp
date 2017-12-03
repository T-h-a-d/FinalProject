/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Warden's Office class. This class is 
** derived from the Space class and inherits all of its member variables and functions. 
** This class also overrides functions to check if there is a special item needed to enter
** the room, print the item needed to enter the room(if there is one), get the name of the
** item needed to enter the room, and inspect the room. Inspect the room allows the player
** to interact with the room. 
*******************************************************************************************/
#include "Wardens_Office.hpp"

/******************************************************************************************
** Constructor: Warden's Office
** Description: Constructs a Wardens Office object. Initializes the name of the space to 
** "Warden's Office", dynamically allocates a new Wardens_Mask item, and sets the 
** has_wardens_mask boolean to true.
*******************************************************************************************/

Wardens_Office::Wardens_Office()
{
	name = "Warden's Office";
	has_wardens_mask = true;
	wardens_mask = new Wardens_Mask;
}

/******************************************************************************************
** Function: item_needed
** Description: Returns true because the keycard is needed to enter this space.
*******************************************************************************************/

bool Wardens_Office::item_needed()
{
	return(true);
}

/******************************************************************************************
** Function: print_item_needed
** Description: Prints the item that is needed to enter the Wardens_Office along with a 
** description of where to find it.
*******************************************************************************************/

void Wardens_Office::print_item_needed()
{
	std::cout << std::endl;
	std::cout << "You need the Warden's Key Card to access this area!" << std::endl;
	std::cout << "Hint: Inspect the Prison Yard ... the Warden is clumsy." << std::endl;
	std::cout << std::endl;
}

/******************************************************************************************
** Function: get_name_of_item_needed
** Description: Returns a string that represents the name of the item needed to enter
** the room. 
*******************************************************************************************/

std::string Wardens_Office::get_name_of_item_needed()
{
	return("Key Card");
}

/******************************************************************************************
** Function: inspect_room
** Description: Takes a person pointer as a parameter and asks the user if they would like
** to pick up the wardens_mask object. If they say yes, then the function will check if their
** backpack is full. If it is not, the item is added to the backpack. If the backpack is
** full, then the user is asked if they would like to delete an item to make room for the
** wardens_mask. If they say yes, then the user is asked which item they would like to delete.
** The function then changes the person's backpack based upon these choices.
*******************************************************************************************/

void Wardens_Office::inspect_room(Person* p)
{
	if(has_wardens_mask)
	{
		int user_choice;

		std::cout << std::endl;
		std::cout << "You look at the Warden's desk and see a strange mask on top of it" << std::endl;
		std::cout << "... It's a mask of the Warden's face" << std::endl;
		std::cout << std::endl;

		std::cout << "1. Put on the Warden's Mask" << std::endl;
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

/******************************************************************************************
** Destructor: Wardens_Office
** Description: Destroys a Wardens_Office object and deletes all of the previously dynamically 
** allocated objects.
*******************************************************************************************/

Wardens_Office::~Wardens_Office()
{
	//Delete dynamically allocated item
	delete wardens_mask;
}
