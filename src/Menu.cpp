/***************************************************************************************
** Thad Sauter
** 10/8/17
** Description: Menu function implementation section. These functions allow for prompts 
** to be output to the user and then validates different user inputs. This will be 
** added to in the future, and maybe even made into a class for better organization.
****************************************************************************************/
#include <iostream>
#include <string>
#include "Menu.hpp"

void Make_Menu_Option(std::string option1, int option_number)
{


	std::cout << option_number << ". " << option1 << std::endl;
	
}

void Menu_Pos_Int_Prompt(std::string prompt, int &num)
{
	std::cout << prompt;

	num = int_validation_positive();  //validate pos number
}

void Menu_Range_Int_Prompt(std::string prompt, int &num, int min, int max)
{
	std::cout << prompt << std::endl;

	num = int_validation_range(min, max); //validate within range
}

// Test Comment
