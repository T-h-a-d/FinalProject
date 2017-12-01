/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Inmate.hpp"


Inmate::Inmate()
{


	
}


bool Inmate::kill_guard()
{
	int user_choice;

	std::cout << "You ended up in the same room as the guard ... but you have a gun." << std::endl;
	std::cout << "1. Shoot guard" << std::endl;
	std::cout << "2. Leave guard alone and lose the game" << std::endl;

	Menu_Range_Int_Prompt("", user_choice, 1, 2);

	switch(user_choice)
	{
		case 1:
		{
			return(true);
		}

		case 2:
		{
			return(false);
		}
	}


}
