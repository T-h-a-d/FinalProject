/***************************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: Function implementation for the Space Class. This class contains 4 member variables,
** right, left, top, and bottom which are Space pointers and correspond to the adjacent
** Spaces to the current Space. These Space pointers will be used to connect different 
** types of Space into a 2-d like structure. The Space class also has a member variable,
** name, to keep track of the name of the space. The Space class has member functions to,
** get the name of a space, set an adjacent space, get an adjacent space, print room 
** options for the player and get the choice, randomly move the guard. The Space class also
** has virtual member functions to check if a player is done_digging (overriden by Jail_Cell),
** check if a certain item is needed to enter a Space, print text about the item needed to 
** enter a Space, get the name of the item needed to enter the Space, and inspect a room.
** The class also has a virtual destructor.
****************************************************************************************************/
#include "Space.hpp"
#include "Person.hpp"

/******************************************************************************************
** Function: get_name
** Description: Function which returns a string, the name of the Space.
*******************************************************************************************/

std::string Space::get_name()
{
	return(name);
}

/******************************************************************************************
** Function: set_adjacent_spaces
** Description: Function which takes in a string representing the direction and a Space 
** pointer which represents the adjacent space. Based on the direction entered, the 
** function sets the adjacent Space, right, left, top, or bottom equal to the Space pointer
** parameter.
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
** Function: get_adjacent_space
** Description: Function which takes in a direction as a parameter and returns the Space 
** pointer that is in that specfified direction.
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
** Function: room_options_player
** Description: Function which prints out the options of rooms to travel to, gets the users
** input, and then returns a string based on which direction the user chose to travel. This
** string representing direction will then be used to move the player in the game 
** implementation class.
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
** Function: room_options_guard
** Description: Function which keeps track of the valid rooms for a guard to travel to and
** then randomly assigns the guard a valid direction to move in. The direction which is 
** represented a string is then returned from the function and used to move the guard in
** the game implementation class.
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
** Function: inspect_room
** Description: Pure virtaul function that will be overriden by every derived class from 
** Space.
*******************************************************************************************/

void Space::inspect_room(Person*)
{



}

/******************************************************************************************
** Function: done_digging
** Description: Virtual function which will be overriden by the Jail_Cell class to check 
** if a person is done digging.
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