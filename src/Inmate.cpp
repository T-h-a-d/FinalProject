/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation file for the Inmate class. This class is derived
** from the Person class and inherits all of its member variables and functions.
*******************************************************************************************/
#include "Inmate.hpp"

/******************************************************************************************
** Constructor: Inmate
** Description: Constructs an Inmate object and sets its type to "Inmate". Also sets the
** inmates digging speed to 1 and the boolean variable under_influence to false.
*******************************************************************************************/

Inmate::Inmate()
{
	type = "Inmate";
	
	//dig_speed initially set to 1
	dig_speed = 1;	

	//Inmate is not initially under the influence 
	under_influence = false;
}

/******************************************************************************************
** Function: kill_guard
** Description: Overriden function from the Person class. This function asks the user if 
** they would like to kill the guard, or if they would like to let the guard live. The 
** function returns true if the user decided to kill the guard and false otherwise.
*******************************************************************************************/

bool Inmate::kill_guard()
{
	int user_choice;

	std::cout << "You ended up in the same room as the guard ... but you have a gun." << std::endl;
	std::cout << "1. Shoot guard" << std::endl;
	std::cout << "2. Do the right thing and let the guard live" << std::endl;

	Menu_Range_Int_Prompt("", user_choice, 1, 2);

	switch(user_choice)
	{
		case 1:
		{
			return(true);
		}

		case 2:
		{
			std::cout << "You fool!" << std::endl;
			return(false);
		}
	}
}
