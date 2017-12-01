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
}

bool Hallway::item_needed()
{
	return(false);
}

void Hallway::print_item_needed()
{

	
}

std::string Hallway::get_name_of_item_needed()
{
	return("");
}

void Hallway::inspect_room(Person* p)
{
	int user_choice;

	std::cout << "Wow this is a dirty ward. Do they ever clean up around here?" << std::endl;
	std::cout << "Oh look a steroid syringe!" << std::endl;

	std::cout << "1. Pick up syringe" << std::endl;
	std::cout << "2. Leave that nasty thing where it belongs" << std::endl;

	Menu_Range_Int_Prompt("", user_choice, 1, 2);

	switch(user_choice)
	{
		case 1:
		{
			std::cout << "I can't believe you actually picked that up ..." << std::endl;
			std::cout << "You start to feel a rage ... " << std::endl;
			std::cout << "Huh ... digging out of your cell might actually be faster now" << std::endl;

			p->add_item(syringe);
		}

		case 2:
		{
			std::cout << "Good choice" << std::endl;
		}
	}
}
