/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Infirmary class. This class is 
** derived from the Space class and inherits all of its member variables and functions. 
** This class also overrides functions to check if there is a special item needed to enter
** the room, print the item needed to enter the room(if there is one), get the name of the
** item needed to enter the room, and inspect the room. Inspect the room allows the player
** to interact with the room. 
*******************************************************************************************/
#include "Infirmary.hpp"

/******************************************************************************************
** Constructor: Infirmary
** Description: Constructs an Infirmary object and sets its name to "Infirmary"
*******************************************************************************************/
Infirmary::Infirmary()
{
	name = "Infirmary";
}

/******************************************************************************************
** Function: item_needed
** Description: Boolean function which returns false because no items are needed to enter
** the Hallway.
*******************************************************************************************/

bool Infirmary::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: print_item_needed
** Description: Prints nothing because no items are needed.
*******************************************************************************************/

void Infirmary::print_item_needed()
{

	
}

/******************************************************************************************
** Function: get_name_of_item_needed
** Description: Returns a string that represents the name of the item needed to enter
** the room. Note: The player does not need a specific item to enter this room.
*******************************************************************************************/

std::string Infirmary::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: inspect_room
** Description: Takes a person pointer as a parameter and checks the persons backpack to 
** see if they have the syringe. If they do have the item, then the function asks if the
** user would like to have the syringe adminstered by the nurse. If they say yes, the 
** digging speed of the person is changed and the syringe is removed from the backpack.
** Otherwise, nothing happens and a string is printed out giving a hint as to what the 
** Infirmary space is for.
*******************************************************************************************/

void Infirmary::inspect_room(Person* p)
{
	if(p->player_has_item("Syringe"))
	{
		int user_choice;

		std::cout << "The nurse in the infirmary is somehow awake ..." << std::endl;
		std::cout << "Would you like to have her administer the PCP syringe?" << std::endl;
		Make_Menu_Option("Yes, gimme that strength", 1);
		Make_Menu_Option("No, I want to save it for later", 2);

		Menu_Range_Int_Prompt("", user_choice, 1, 2);

		switch(user_choice)
		{
			case 1:
			{
				p->use_syringe();
				p->delete_specific_item("Syringe");

				break;
			}

			case 2:
			{
				//Nothing happens, user decided to save for later
			}
		}
	}

	else
	{
		std::cout << std::endl;
		std::cout << "The nurse says she is very good at adminstering illegal drugs" << std::endl;
		std::cout << "If only you had an illegal substance that would increase strength and stamina ..." << std::endl;
		std::cout << std::endl;
	}
}