/********************************************************************************************
** Utility Class
** Author: Thad Sauter
** Date: 10/8/17
** Description: This is a utility class implementation file that will be added to throughout 
** the quarter. For now, the main point of the utility class is to validate user inputs, but 
** any functions that can assist and speed up program development will be added here. 
** Adapted from http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
**********************************************************************************************/
#include <iostream>
#include "Utility_Functions.hpp"

/**********************************************************************************************
** Function: int_validation
** Description: Checks if user input is an integer. If it is not,the function prompts the user 
** to enter another input. Returns the integer once it is recieved.
***********************************************************************************************/

int int_validation()
{
	int num = 0;

	while (!(std::cin >> num)) 
	{
		std::cout << "Please enter an integer." << std::endl;

		std::cin.clear(); // reset back to goodbit to use ignore

		std::cin.ignore(1000, '\n'); 
	}

	return num;
}

/************************************************************************************************
** Function: int_validation_range
** Description: Checks if user input is an integer within a certain range. Takes a min and max 
** inputs as parameters and returns the integer once it is recieves.
*************************************************************************************************/

int int_validation_range(const int min, const int max)
{
	int num;
	bool valid = false;

	do
	{
		num = int_validation();

		if (num < min || num > max)
		{
			std::cout << "Please enter a value between " << min << " and " << max << std::endl;
		}

		else
		{
			valid = true;
		}
	}
	while (!valid);

	return num;
}

/************************************************************************************************
** Function: int_validation
** Description: Checks if user input is an integer greater than 0. If it is not, the function 
** prompts the user to enter another input. Returns the integer once it is recieved. 
*************************************************************************************************/

int int_validation_positive()
{
	int num;
	bool valid = false;

	do
	{
		num = int_validation();

		if (num <= 0)
		{
			std::cout << "Please enter a positive value" <<std::endl;
		}

		else
		{
			valid = true;
		}
	}
	while (!valid);

	return num;
}