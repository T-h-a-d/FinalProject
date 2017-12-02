/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Jail_Cell.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Jail_Cell::Jail_Cell()
{
	name = "Jail Cell";
	minutes_dug = 0;

	//Takes 4 hours to dig the hole with just the spoon (no drugs)
	minutes_to_completion = 240;
	total_min_needed = 240;

}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Jail_Cell::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Jail_Cell::print_item_needed()
{


}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Jail_Cell::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: 
** Description: 
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
** Function: 
** Description: 
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