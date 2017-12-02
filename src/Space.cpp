/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Space.hpp"
#include "Person.hpp"

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Space::get_name()
{
	return(name);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Space::set_adjacent_spaces(std::string direction, Space* spc)
{
	if(direction == "right")
	{
		right = spc;
	}

	else if(direction == "left")
	{
		left = spc;
	}

	else if(direction == "top")
	{
		top = spc;
	}

	else
	{
		bottom = spc;
	}
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

Space* Space::get_adjacent_space(std::string direction)
{
	if(direction == "right")
	{
		return(right);
	}

	else if(direction == "left")
	{
		return(left);
	}

	else if(direction == "top")
	{
		return(top);
	}

	else
	{
		return(bottom);
	}
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Space::room_options_player()
{
	int user_location_choice;
	int print_options = 1;
	int num_array[4];

	//Set all elements in array to zero
	for(int i = 0; i < 4; i++)
	{
		num_array[i] = 0;
	}

	if(right != nullptr)
	{
		std::cout << print_options << ". ";
		std::cout << right->get_name() << std::endl;
		print_options++;

		//right = 1
		num_array[print_options - 2] = 1;
	}

	if(left != nullptr)
	{
		std::cout << print_options << ". ";
		std::cout << left->get_name() << std::endl;
		print_options++;

		//left = 2
		num_array[print_options - 2] = 2;
	}

	if(top != nullptr)
	{
		std::cout << print_options << ". ";
		std::cout << top->get_name() << std::endl;
		print_options++;

		//top = 3
		num_array[print_options - 2] = 3;
	}

	if(bottom != nullptr)
	{
		std::cout << print_options << ". ";
		std::cout << bottom->get_name() << std::endl;
		print_options++;

		//bottom = 4
		num_array[print_options - 2] = 4;
	}

	Menu_Range_Int_Prompt("", user_location_choice, 1, (print_options - 1));

	int choice = num_array[user_location_choice - 1];

	switch(choice)
	{
		case 1:
		{
			return "right";
		}

		case 2:
		{
			return "left";
		}

		case 3:
		{
			return "top";
		}

		case 4:
		{
			return "bottom";
		}
	}
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

std::string Space::room_options_guard()
{
	int guard_location_choice;
	int print_options = 1;
	int num_array[4];

	//Set all elements in array to zero
	for(int i = 0; i < 4; i++)
	{
		num_array[i] = 0;
	}

	if(right != nullptr)
	{
		print_options++;

		//right = 1
		num_array[print_options - 2] = 1;
	}

	if(left != nullptr)
	{
		print_options++;

		//left = 2
		num_array[print_options - 2] = 2;
	}

	if(top != nullptr)
	{
		print_options++;

		//top = 3
		num_array[print_options - 2] = 3;
	}

	if(bottom != nullptr)
	{
		print_options++;

		//bottom = 4
		num_array[print_options - 2] = 4;
	}

	guard_location_choice = rand() % (print_options - 1) + 1;

	int choice = num_array[guard_location_choice - 1];

	switch(choice)
	{
		case 1:
		{
			return "right";
		}

		case 2:
		{
			return "left";
		}

		case 3:
		{
			return "top";
		}

		case 4:
		{
			return "bottom";
		}
	}
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Space::inspect_room(Person*)
{



}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Space::done_digging()
{

}


/******************************************************************************************
** Destructor: Space
** Description: Destroys a Space object.
*******************************************************************************************/
Space::~Space()
{



}