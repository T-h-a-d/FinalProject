/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation section for the Jail_Cell class. This class is 
** derived from the Space class and inherits all of its member variables and functions. 
** This class also overrides functions to check if there is a special item needed to enter
** the room, print the item needed to enter the room(if there is one), get the name of the
** item needed to enter the room, and inspect the room. Inspect the room allows the player
** to interact with the room. This class also contains member variables to keep track of if 
** the player has started digging a hole, if the whole is done being dug, how many minutes 
** the player has dug for, and how many more minutes are needed to finish.
*******************************************************************************************/
#include "Jail_Cell.hpp"

/******************************************************************************************
** Constructor: Jail_Cell
** Description: Constructs a Jail_Cell object. The constructor initialzes the name of the 
** object to "Jail Cell", and the rest of the member variables that describe the 
** prisoners escape hole.
*******************************************************************************************/

Jail_Cell::Jail_Cell()
{
	name = "Jail Cell";
	minutes_dug = 0;
	hole = false;

	//Takes 4 hours to dig the hole with just the spoon (no drugs)
	minutes_to_completion = 240;
	total_min_needed = 240;

}

/******************************************************************************************
** Function: item_needed
** Description: Boolean function which returns false becasue no items are needed to enter
** the jail cell.
*******************************************************************************************/

bool Jail_Cell::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: print_item_needed
** Description: No items are printed because no items are needed to enter this space
*******************************************************************************************/

void Jail_Cell::print_item_needed()
{


}

/******************************************************************************************
** Function: get_name_of_item_needed
** Description: Returns a string that represents the name of the item needed to enter
** the room. Note: The player does not need a specific item to enter this room.
*******************************************************************************************/

std::string Jail_Cell::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: inspect_room
** Description: Takes a person pointer as a parameter and checks the persons backpack for
** the spoon object. If they player has the spoon and if the hole has not been started yet,
** the player is asked if they would like to start digging the hole. If the hole has 
** already been started, then the player can choose to continue digging the hole. The 
** percentage of the hole dug is displayed every round that the inspect room function is 
** chosen for this space, and it is much quicker to dig if adminstered the syringe first.
*******************************************************************************************/

void Jail_Cell::inspect_room(Person* p)
{
	if(p->player_has_item("Spoon"))
	{
		int user_choice;

		int dig_time;

		float percentage_dug;

		float prev_min_to_completion;

		//Hole has not been created yet
		if(hole == false)
		{
			std::cout << std::endl;
			std::cout << "I wonder how easy it would be to escape by digging a hole?" << std::endl;
			std::cout << "Might as well try ..." << std::endl;
			std::cout << std::endl;

			std::cout << "1. Start digging hole" << std::endl;
			std::cout << "2. I refuse to dig" << std::endl;

			Menu_Range_Int_Prompt("", user_choice, 1, 2);

			switch(user_choice)
			{
				case 1:
				{
					hole = true;

					if(p->is_under_influence())
					{
						std::cout << std::endl;
						std::cout << "You are a beast! This hole will be done in no time" << std::endl;
						std::cout << std::endl;

						//10 minutes of drug induced digging
						dig_time = (p->get_dig_speed() * 10);

						minutes_to_completion = minutes_to_completion - dig_time;

						percentage_dug = ((minutes_to_completion/total_min_needed)) * 100;

						std::cout << "Percentage of hole left to dig: ";
						std::cout << percentage_dug << "%" << std::endl;
					}

					else
					{
						std::cout << std::endl;
						std::cout << "Whew! It would take at least 4 hours to escape with my pace right now" << std::endl;
						std::cout << "If only there were a faster way to dig ..."<< std::endl;
						std::cout << std::endl;

						//10 minutes of normal digging
						dig_time = (p->get_dig_speed() * 10);

						minutes_to_completion = minutes_to_completion - dig_time;

						percentage_dug = ((minutes_to_completion/total_min_needed)) * 100;

						std::cout << "Percentage of hole left to dig: ";
						std::cout << percentage_dug << "%" << std::endl;
					}

					break;
				}

				case 2:
				{
		      //Nothing happens
				}
			}
		}

		//Hole has already been created
		else
		{
			std::cout << std::endl;
			std::cout << "1. Continue digging hole" << std::endl;
			std::cout << "2. I will not dig another inch" << std::endl;
			std::cout << std::endl;

			Menu_Range_Int_Prompt("", user_choice, 1, 2);

			switch(user_choice)
			{
				case 1:
				{
					if(p->is_under_influence())
					{
						std::cout << std::endl;
						std::cout << "You are a beast! This hole will be done in no time" << std::endl;
						std::cout << std::endl;

						//10 minutes of drug induced digging
						dig_time = (p->get_dig_speed() * 10);

						minutes_to_completion = minutes_to_completion - dig_time;

						percentage_dug = ((minutes_to_completion/total_min_needed)) * 100;

						std::cout << "Percentage of hole left to dig: ";
						std::cout << percentage_dug << "%" << std::endl;
					}

					else
					{
						std::cout << std::endl;
						std::cout << "Whew! It would take at least 4 hours to escape with my pace right now" << std::endl;
						std::cout << "If only there were a faster way to dig ..." << std::endl;
						std::cout << std::endl;

						//10 minutes of normal digging
						dig_time = (p->get_dig_speed() * 10);

						minutes_to_completion = minutes_to_completion - dig_time;

						percentage_dug = ((minutes_to_completion/total_min_needed)) * 100;

						std::cout << "Percentage of hole left to dig: ";
						std::cout << percentage_dug << "%" << std::endl;
					}

					break;
				}

				case 2:
				{
		      //Nothing happens
				}
			}

		}
	}

	else
	{
		std::cout << std::endl;
		std::cout << "There must be some way to escape from here ..." << std::endl;
		std::cout << std::endl;
	}
}

/******************************************************************************************
** Function: done_digging
** Description: Function which checks if the minutes_to_completion is 0. Returns true if it
** is zero, and false otherwise.
*******************************************************************************************/

bool Jail_Cell::done_digging()
{
	if(minutes_to_completion == 0)
	{
		return(true);
	}

	else
	{
		return(false);
	}
}