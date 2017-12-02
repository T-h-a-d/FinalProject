/******************************************************************************************
** Final Project: Jail Escape
** Thad Sauter
** 12/5/17
** Description: 
*******************************************************************************************/
#include "Play_Jail_Escape.hpp"

/******************************************************************************************
** Constructor: 
** Description: 
*******************************************************************************************/

Play_Jail_Escape::Play_Jail_Escape()
{
	//Dynamically allocate spaces
	jail_cell = new Jail_Cell;
	hallway1  = new Hallway("Prison Cell Hallway");
	hallway2  = new Hallway("Hallway to Infirmary");
  hallway3  = new Hallway("Hallway to Entrance");
  yard 			= new Prison_Yard;	
  infirmary = new Infirmary;
  kitchen 	= new Kitchen;
  entrance	= new Entrance;
	wardens_office = new Wardens_Office;

	//Dynaimcally allocate a guard and an inmate
	guard = new Guard;
	inmate = new Inmate;

	//Inmate starts in jail, guard starts at the entrance
	inmate->set_location(jail_cell);
	guard->set_location(entrance);

	//Connect rooms to each other

	//Set up jail_cell connections
	jail_cell->set_adjacent_spaces("left", hallway2);
	jail_cell->set_adjacent_spaces("top", hallway1);
	jail_cell->set_adjacent_spaces("bottom", nullptr);
	jail_cell->set_adjacent_spaces("right", nullptr);

	//Set up hallway1 connections
	hallway1->set_adjacent_spaces("left", yard);
	hallway1->set_adjacent_spaces("top", nullptr);
	hallway1->set_adjacent_spaces("bottom", jail_cell);
	hallway1->set_adjacent_spaces("right", nullptr);

	//Set up hallway2 connections
	hallway2->set_adjacent_spaces("left", infirmary);
	hallway2->set_adjacent_spaces("top", yard);
	hallway2->set_adjacent_spaces("bottom", nullptr);
	hallway2->set_adjacent_spaces("right", jail_cell);

	//Set up prison_yard connections
	yard->set_adjacent_spaces("left", kitchen);
	yard->set_adjacent_spaces("top", wardens_office);
	yard->set_adjacent_spaces("bottom", hallway2);
	yard->set_adjacent_spaces("right", hallway1);

	//Set up infirmary connections
	infirmary->set_adjacent_spaces("left", nullptr);
	infirmary->set_adjacent_spaces("top", kitchen);
	infirmary->set_adjacent_spaces("bottom", nullptr);
	infirmary->set_adjacent_spaces("right", hallway2);

	//Set up kitchen connections
	kitchen->set_adjacent_spaces("left", nullptr);
	kitchen->set_adjacent_spaces("top", hallway3);
	kitchen->set_adjacent_spaces("bottom", infirmary);
	kitchen->set_adjacent_spaces("right", yard);

	//Set up wardens office connections
	wardens_office->set_adjacent_spaces("left", nullptr);
	wardens_office->set_adjacent_spaces("top", nullptr);
	wardens_office->set_adjacent_spaces("bottom", yard);
	wardens_office->set_adjacent_spaces("right", nullptr);

	//Set up hallway3 connections
	hallway3->set_adjacent_spaces("left", entrance);
	hallway3->set_adjacent_spaces("top", nullptr);
	hallway3->set_adjacent_spaces("bottom", kitchen);
	hallway3->set_adjacent_spaces("right", nullptr);

	//Set up entrance connections
	entrance->set_adjacent_spaces("left", nullptr );
	entrance->set_adjacent_spaces("top", nullptr);
	entrance->set_adjacent_spaces("bottom", nullptr);
	entrance->set_adjacent_spaces("right", hallway3);

	//Initialize game_minutes to zero
	game_minutes = 0;

	//Starting hour is 1:00 am
	starting_hour = 1;
	minutes = 0;

}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Play_Jail_Escape::start_game()
{
	bool test = true;

	do
	{
		print_clock();

		int user_choice_1 = print_user_options();

		switch(user_choice_1)
		{
			case(1):
			{
				std::string user_direction;
				int num_locations;

				std::cout << "Where would you like to go?" << std::endl;
				std::cout << std::endl;
				user_direction = inmate->get_location()->room_options();

				move_person(inmate, user_direction);

				break;
			}

			case(2):
			{
				//Interact with the room
				inmate->get_location()->inspect_room(inmate);

				break;

			}

			case(3):
			{
				inmate->print_backpack_contents();
			}
		}

		//Print out guard location if user has guard_radio
		if(inmate->player_has_item("Guard's Radio"))
		{
			std::cout << "Guard's Current Location: ";
			std::cout << guard->get_location()->get_name() << std::endl;
		}

		//Each action takes 10 minutes
		game_minutes = game_minutes + 10;
		minutes = minutes + 10;

	}
	while(!check_if_game_over());
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

void Play_Jail_Escape::move_person(Person* p, std::string direction)
{
	//Get current location of person
	Space* current_position = p->get_location();

	//Check if player needs access to get into certain space
	if(current_position->get_adjacent_space(direction)->item_needed())
	{
		std::string item_name = current_position->get_adjacent_space(direction)->get_name_of_item_needed();

		//Player has the item needed to enter the space
		if(p->player_has_item(item_name))
		{
			//Set new position equal the direction that the user entered
			Space* new_position = current_position->get_adjacent_space(direction);
			p->set_location(new_position);
		}

		//Player does not have required access to the space
		else
		{
			current_position->get_adjacent_space(direction)->print_item_needed();
		}
	}

	//No item is required to enter the space
	else
	{
		//Set new position equal the direction that the user entered
		Space* new_position = current_position->get_adjacent_space(direction);
		p->set_location(new_position);
	}
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Play_Jail_Escape::check_location(Person* p1, Person* p2)
{
	bool same_location;

	std::string p1_location = p1->get_location()->get_name();
	std::string p2_location = p2->get_location()->get_name();

	if(p1_location == p2_location)
	{
		same_location = true;
	}

	else
	{
		same_location = false;
	}

	return(same_location);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

int Play_Jail_Escape::print_user_options()
{
	int user_choice;

	std::cout << "1. Travel to another room " << std::endl;
	std::cout << "2. Inspect current room" << std::endl;
	std::cout << "3. Look at contents of backpack" << std::endl;

	Menu_Range_Int_Prompt("", user_choice, 1, 3);

	return(user_choice);
}

/******************************************************************************************
** Function: 
** Description: 
*******************************************************************************************/

bool Play_Jail_Escape::check_if_game_over()
{
	bool game_over = false;

	if(jail_cell->done_digging() == true)
	{
		std::cout << std::endl;
		std::cout << "You have escaped from Jail!" << std::endl;
		std::cout << std::endl;
		std::cout << "YOU WIN" << std::endl;
		return(true);
	}

	//Check if the inmate and guard end up in the same room
	if(check_location(inmate, guard) == true)
	{
		//Inmate can choose to shoot the guard
		if(inmate->player_has_item("gun"))
		{
			if(inmate->kill_guard())
			{
				game_over = false;
			}

			else
			{
				std::cout << "You've been caught by the guard ... !" << std::endl;
				std::cout << std::endl;
				std::cout << "GAME OVER" << std::endl;
				std::cout << std::endl;
				game_over = true;
			}
		}

		else
		{
			std::cout << "You've been caught by the guard ... !" << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
			std::cout << std::endl;

			game_over = true;
		}	
	}

	//Prisoner has 6 hours to escape
	if(game_minutes == 360)
	{
		std::cout << "You ran out of time!" << std::endl;
		std::cout << std::endl;
		std::cout << "GAME OVER" << std::endl;
		std::cout << std::endl;

		game_over = true;
	}

	return(game_over);
}

void Play_Jail_Escape::print_clock()
{
	if(game_minutes % 60 == 0)
	{
		if(game_minutes == 0)
		{
			//Do nothing
		}
		else
		{
			starting_hour++;
			minutes = 0;
		}
	}

	if(minutes == 0)
	{
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "---------------- Time: "<< starting_hour << ":" << minutes << "0";
		std::cout << " -----------------" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}

	else
	{
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "---------------- Time: "<< starting_hour << ":" << minutes;
		std::cout << " -----------------" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

/******************************************************************************************
** Destructor: 
** Description: 
*******************************************************************************************/

Play_Jail_Escape::~Play_Jail_Escape()
{
	//Get rid of dynamically allocated spaces
	delete jail_cell;
	delete hallway1;
	delete hallway2;
  delete hallway3;
  delete yard;	
  delete infirmary;
  delete kitchen;
  delete entrance;
	delete wardens_office;

	//Get rid of dynamically allocated person objects
	delete guard;
	delete inmate;
}