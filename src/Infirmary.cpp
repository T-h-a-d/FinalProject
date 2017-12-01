/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Infirmary.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Infirmary::Infirmary()
{
	name = "Infirmary";
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Infirmary::item_needed()
{
	return(false);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Infirmary::print_item_needed()
{

	
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Infirmary::get_name_of_item_needed()
{
	return("");
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Infirmary::inspect_room(Person* p)
{
	if(p->player_has_item("syringe"))
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
				p->delete_specific_item("syringe");
				p->under_influence();

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